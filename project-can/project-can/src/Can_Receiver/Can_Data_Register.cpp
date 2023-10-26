#include "Can_Data_Register.hpp"

#include <iostream>
#include <thread>

using namespace v1_0::DES_Project3;

CanDataRegister::CanDataRegister() {

    runtime = CommonAPI::Runtime::get();
    SpeedRpmService = std::make_shared<Speed_SensorStubImpl>();

    Speed_Sensor_Init();

}

CanDataRegister::~CanDataRegister() {}

void CanDataRegister::Speed_Sensor_Init(){
    while(!runtime->registerService("local", "Speed_Sensor", SpeedRpmService, "SpeedRpm_Service")){
        std::cout << "Register SpeedRpm Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered SpeedRpm Service!" << std::endl;
}

void CanDataRegister::sendDataToVSomeIP(uint32_t rpm, uint32_t speed) {
    // Set RPM and Speed values via the Speed_SensorStubImpl
    SpeedRpmService->setRpmAttribute(rpm);
    SpeedRpmService->setSpeedAttribute(speed);
}

