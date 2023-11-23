#include "Can_Receiver.hpp"

CanReceiver::CanReceiver() : raw_rpm(0), running(false) {}

CanReceiver::~CanReceiver() {}

int CanReceiver::openPort(const char* iface) {
    struct sockaddr_can addr;
    struct ifreq ifr;

    if((soc = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0 ) {
        perror("Socket creation error");
        return -1;
    }

    std::strcpy(ifr.ifr_name , iface);
    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    // Set the socket timeout to 10 seconds
    struct timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    if (setsockopt(soc, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("Failed to set socket timeout");
        return -1;
    }

    return 0;
}

void CanReceiver::readData() {
    struct can_frame frame;

    while(running) {
        ssize_t nbytes = recv(soc, &frame, sizeof(struct can_frame), MSG_WAITALL);

        if (nbytes < 0) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                // This means a timeout occurred
                std::cerr << "Receive timeout occurred! Stopping..." << std::endl;
                running = false;
                break;
            } else {
                // Some other error occurred during reading
                perror("Failed to receive data");
                continue;
            }
        }

        if(nbytes == sizeof(struct can_frame)) {
            last_received_time = std::chrono::steady_clock::now();
        }

        {
            std::lock_guard<std::mutex> lock(dataMutex);
            std::memcpy(&raw_rpm, frame.data, sizeof(int));
        }
    }
}

void CanReceiver::processAndFilterData() {
    MovingAverageFilter rpmFilter(10, 5);
    
    double PI = M_PI;
    double filtered_rpm;
    double filtered_speed;

    while(running) {
        int current_rpm;
        {
            std::lock_guard<std::mutex> lock(dataMutex);
            current_rpm = raw_rpm;
        }
        
        filtered_rpm = rpmFilter.filter(current_rpm);
        

        filtered_speed = (((filtered_rpm * FACTOR) / WHEEL_RADIUS) * PI) * WHEEL_RADIUS;

        std::cout << "Filtered RPM : " << filtered_rpm << ", Filtered Speed : " << filtered_speed << std::endl;

        dataRegister.sendDataToVSomeIP(static_cast<uint32_t>(filtered_rpm), static_cast<uint32_t>(filtered_speed));


        usleep(100000); // 0.1sec
    }
}


void CanReceiver::closePort() {
    close(soc);
}

int CanReceiver::run() {
    if (openPort(CAN_INTERFACE) < 0) {
        return -1;
    }

    running = true;
    last_received_time = std::chrono::steady_clock::now();

    std::thread readerThread(&CanReceiver::readData, this);
    std::thread processorThread(&CanReceiver::processAndFilterData, this);

    readerThread.join();
    processorThread.join();


    closePort();

    return 0;
}
