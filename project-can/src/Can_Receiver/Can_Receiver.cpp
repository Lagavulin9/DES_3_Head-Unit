#include "Can_Receiver.hpp"
#include "Can_Moving_Average_Filter.hpp"
#include "Can_Data_Register.hpp"

#include <thread>
#include <mutex>
#include <csignal>
#include <atomic>


const char* CAN_INTERFACE = "can0";
int soc;

const double FACTOR = 0.025;
const double WHEEL_RADIUS = 0.065;
const int SLEEP_DURATION_US = 100000;

std::mutex dataMutex;
int raw_rpm = 0;
double speed = 0.0;

std::atomic<bool> running;

Moving_Average_Filter rpmFilter(5);

void signalHandler(int signum){
    running = false;
}

int open_port(const char* iface){
    struct sockaddr_can addr;
    struct ifreq ifr;

    // create socket
    if((soc = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0 ) {
        perror("Socket creation error");
        return -1;
    }

    // Set CAN Interface Name
    std::strcpy(ifr.ifr_name , iface);
    ioctl(soc, SIOCGIFINDEX, &ifr);

    // Set Socket Address
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    // Bind Socket with CAN Interface
    if(bind(soc, (struct sockaddr *)&addr, sizeof(addr)) < 0 ) {
        perror("Bind error");
        return -1;
    }

    return 0;
}

void read_Data(){
    struct can_frame frame;

    while(running){
       
        ssize_t nbytes = recvfrom(soc, &frame, sizeof(struct can_frame), 0, NULL, NULL);
            
        if(nbytes < 0){
            perror("Read error");
            break;
        }

        if(nbytes < sizeof(struct can_frame)){
            perror("Incomplete CAN frame");
            continue;
        }
       
        {
            std::lock_guard<std::mutex> lock(dataMutex);
            std::memcpy(&raw_rpm, frame.data, sizeof(int));
        }
    }
}

void processAndFilterData() {

    CanDataRegister dataRegister;

    while(running){
        double filtered_rpm;
        
        {
            std::lock_guard<std::mutex> lock(dataMutex);
            filtered_rpm = rpmFilter.filter(raw_rpm);
        }

        filtered_rpm = (filtered_rpm * FACTOR) / WHEEL_RADIUS;
        speed = filtered_rpm * M_PI * WHEEL_RADIUS;

        std::cout << "Filtered RPM : " << filtered_rpm << ", Filtered Speed : " << speed << std::endl;

        
        dataRegister.sendDataToVSomeIP(filtered_rpm, speed);

        usleep(SLEEP_DURATION_US);
    }
}

void close_port(){
    close(soc);
}

int main() {
    //Set signal Handler for SIGINT(Ctrl + C)
    struct sigaction act;
    act.sa_handler = signalHandler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGINT, &act, NULL);
 
    
    if (open_port(CAN_INTERFACE) < 0) {
        return -1;
    }

    running = true;

    std::thread readerThread(read_Data);  // Modified the function name here
    std::thread processorThread(processAndFilterData);

    readerThread.join();
    processorThread.join();

    close_port();

    return 0;
}
