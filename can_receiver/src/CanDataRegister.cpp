#include "CanDataRegister.hpp"

#include <iostream>
#include <thread>

using namespace v0_1::commonapi;

CanDataRegister::CanDataRegister() {

    runtime = CommonAPI::Runtime::get();
    SpeedRpmService = std::make_shared<SpeedSensorStubImpl>();

    SpeedSensor_Init();

}

CanDataRegister::~CanDataRegister() {}

void CanDataRegister::SpeedSensor_Init(){
    while(!runtime->registerService("local", "SpeedSensor", SpeedRpmService, "SpeedRpmService")){
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

