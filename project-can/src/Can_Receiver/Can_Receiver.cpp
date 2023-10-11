#include "Can_Receiver.hpp"
#include "Can_Moving_Average_Filter.hpp"
#include "Can_Data_Register.hpp"

#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>


const char* CAN_INTERFACE = "can0";
int soc;

const double FACTOR = 0.025;
const double WHEEL_RADIUS = 0.065;

std::mutex dataMutex;
int raw_rpm = 0;
std::atomic<bool> running;
std::chrono::steady_clock::time_point last_received_time;
MovingAverageFilter rpmFilter(10 , 5);

int openPort(const char* iface) {
    struct sockaddr_can addr;
    struct ifreq ifr;

    if((soc = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0 ) {
        perror("Socket creation error");
        return -1;
    }

    std::strcpy(ifr.ifr_name , iface);
    // if(ioctl(soc, SIOCGIFINDEX, &ifr) < 0){
    //     perror("ioctl error");
    //     return -1;
    // }

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    if(bind(soc, (struct sockaddr *)&addr, sizeof(addr)) < 0 ) {
        perror("Bind error");
        return -1;
    }

    return 0;
}

void readData() {
    struct can_frame frame;

    while(running) {
        ssize_t nbytes = read(soc, &frame, sizeof(struct can_frame));

        if(nbytes == sizeof(struct can_frame)) {
            last_received_time = std::chrono::steady_clock::now();
        }

        if(nbytes < sizeof(struct can_frame)) {
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
    double PI = M_PI;

    while(running) {
        double filtered_rpm;
        double filtered_speed;

        {
            std::lock_guard<std::mutex> lock(dataMutex);
            filtered_rpm = rpmFilter.filter(raw_rpm);
        }

        filtered_speed = (((filtered_rpm * FACTOR) / WHEEL_RADIUS) * PI) * WHEEL_RADIUS;

        std::cout << "Filtered RPM : " << filtered_rpm << ", Filtered Speed : " << filtered_speed << std::endl;

        dataRegister.sendDataToVSomeIP(filtered_rpm, filtered_speed);

        usleep(100000); // 0.1sec
    }
}

void checkTimeout() {
    while(running) {
        auto now = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(now - last_received_time).count();

        if(duration > 10) {
            std::cout << "No data for 10 seconds. Setting running to false..." << std::endl;
            running = false;
            break;
        }

        usleep(5000000); // 5secs
    }
}

void closePort() {
    close(soc);
}

int main() {
    if (openPort(CAN_INTERFACE) < 0) {
        return -1;
    }

    running = true;
    last_received_time = std::chrono::steady_clock::now();

    std::thread readerThread(readData);
    std::thread processorThread(processAndFilterData);
    std::thread timeoutCheckerThread(checkTimeout);

    readerThread.join();
    processorThread.join();
    timeoutCheckerThread.join();

    closePort();

    return 0;
}

