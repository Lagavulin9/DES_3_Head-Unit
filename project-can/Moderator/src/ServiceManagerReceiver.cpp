#include "ServiceManagerReceiver.hpp"
#include <iostream>
#include <thread>
#include <unistd.h>

ServiceManagerReceiver::ServiceManagerReceiver() {


    runtime = CommonAPI::Runtime::get();

    ServiceManagerService = std::make_shared<ServiceManagerStubImpl>();

    while(!runtime -> registerService("local", "ServiceManager", ServiceManagerService, "ServiceManager_Service")){
        std::cout << "Register ServiceManager failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered ServiceManager!" << std::endl;
     

    SpeedRpmProxy = runtime->buildProxy<v1_0::Can_Receiver::Speed_SensorProxy>("local", "Speed_Sensor", "Speed_Sensor_Proxy");
    SpeedProxyInit();
    // CarInfoProxy = runtime->buildProxy<v1_0::DES_Project3::Car_InformationProxy>("local", "Car_Information", "Car_Information_Proxy");
    // CarInfoProxyInit();
    // CarControlProxy = runtime->buildProxy<v1_0::DES_Project3::Car_ControlProxy>("local", "Car_Control", "Car_Control_Proxy");
    // CarControlProxyInit();
    // HUProxy = runtime->buildProxy<v1_0::DES_Project3::HUProxy>("local", "HU", "HU_Proxy");
    // HUProxyInit();

}

ServiceManagerReceiver::~ServiceManagerReceiver() {}

void ServiceManagerReceiver::SpeedProxyInit(){
    std::cout << "Checking SpeedProxy Input Availability!" << std::endl;
    while(!SpeedRpmProxy->isAvailable()){
        usleep(100);
    }
    std::cout << "Available ... " << std::endl;  
    
    SpeedRpmProxy->getSpeedAttribute().getChangedEvent().subscribe([&](const uint32_t& speed){
        ServiceManagerService->setSpeedAttribute(speed);
        std::cout<<speed<<std::endl;
    });
    SpeedRpmProxy->getRpmAttribute().getChangedEvent().subscribe([&](const uint32_t& rpm){
        ServiceManagerService->setRpmAttribute(rpm);
    });
}

// void ServiceManagerReceiver::CarInfoProxyInit(){
//     std::cout << "Checking CarInfoProxy Input Availability!" << std::endl;
//     while(!CarInfoProxy->isAvailable())
//         usleep(10);
//     std::cout << "Available ... " << std::endl;  

//     CarControlProxy->getIndicatorAttribute().getChangedEvent().subscribe([&](const std::string& indicator){
//         ServiceManagerService->setIndicatorAttribute(indicator);
//     });
//     CarControlProxy->getGearAttribute().getChangedEvent().subscribe([&](const std::string& gear){
//         ServiceManagerService->setGearAttribute(gear);
//     });
// }


// void ServiceManagerReceiver::CarControlProxyInit(){
//     std::cout << "Checking CarControlProxy Input Availability!" << std::endl;
//     while(!CarControlProxy->isAvailable())
//         usleep(10);
//     std::cout << "Available ... " << std::endl;  
    
//     CarInfoProxy->getBatteryAttribute().getChangedEvent().subscribe([&](const uint8_t& battery){
//         ServiceManagerService->setBatteryAttribute(battery);
//     });
//     CarInfoProxy->getVoltageAttribute().getChangedEvent().subscribe([&](const float& voltage){
//         ServiceManagerService->setVoltageAttribute(voltage);
//     });

//     CarInfoProxy->getCurrentAttribute().getChangedEvent().subscribe([&](const float& current){
//         ServiceManagerService->setCurrentAttribute(current);
//     });
//     CarInfoProxy->getPowerConsumptionAttribute().getChangedEvent().subscribe([&](const float& powerConsumption){
//         ServiceManagerService->setPowerConsumptionAttribute(powerConsumption);
//     });
    
// }


// void ServiceManagerReceiver::HUProxyInit(){
//     std::cout << "Checking HUProxy Input Availability!" << std::endl;
//     while(!HUProxy->isAvailable())
//         usleep(10);
//     std::cout << "Available ... " << std::endl;  
//     HUProxy->getGearSelectionAttribute().getChangedEvent().subscribe([&](const std::string& gearSelection){
//         this->gear = gearSelection;
//     });
  
// }
