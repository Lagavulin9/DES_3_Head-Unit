#ifndef CAN_RECEIVER_HPP
#define CAN_RECEIVER_HPP

#include "Can_Moving_Average_Filter.hpp"
#include "Can_Data_Register.hpp"

#include <iostream>
#include <cstring>
#include <unistd.h>
#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <cmath>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>

class CanReceiver {
public:
    CanReceiver();
    ~CanReceiver();
    int run();

private:
    CanDataRegister dataRegister;

    const char* CAN_INTERFACE = "can0";
    const double FACTOR = 0.025;
    const double WHEEL_RADIUS = 0.065;
    
    int soc;
    std::mutex dataMutex;
    int raw_rpm;
    std::atomic<bool> running;
    std::chrono::steady_clock::time_point last_received_time;

    int openPort(const char* iface);
    void readData();
    void processAndFilterData();
    void closePort();
};

#endif  //  CAN_RECEIVER_HPP
