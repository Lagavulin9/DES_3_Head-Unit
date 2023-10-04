#include "Can_Receiver.hpp"
#include "CAN_Moving_Average_Filter.hpp"

#include <thread>
#include <mutex>

const char* CAN_INTERFACE = "can0";
int soc;

std::mutex dataMutex;
int raw_rpm;
double speed;

Moving_Average_Filter rpmFilter(5);

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
    while(true){
        ssize_t nbytes = recvfrom(soc, &frame, sizeof(struct can_frame), 0, NULL, NULL);
        if(nbytes < 0){
            perror("Read error");
            break;
        }

        if(nbytes < sizeof(struct can_frame)){
            perror("Incomplete CAN frame");
            continue;
        }

        dataMutex.lock();
        std::memcpy(&raw_rpm, frame.data, sizeof(int));
        dataMutex.unlock();
    }
}

void processAndFilterData() {
    while(true){
        dataMutex.lock();
        double filtered_rpm = rpmFilter.filter(raw_rpm);
        speed = filtered_rpm * M_PI * 0.065;
        dataMutex.unlock();

        std::cout << "Filtered RPM : " << filtered_rpm << ", Filtered Speed : " << speed << std::endl;

        // TODO: 여기에서 VSome/IP 서버에 데이터를 등록

        usleep(100000);
    }
}

void close_port(){
    close(soc);
}

int main() {
    if (open_port(CAN_INTERFACE) < 0) {
        return -1;
    }

    std::thread readerThread(read_Data);  // Modified the function name here
    std::thread processorThread(processAndFilterData);

    readerThread.join();
    processorThread.join();

    close_port();

    return 0;
}
