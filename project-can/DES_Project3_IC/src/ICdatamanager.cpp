#include "ICdatamanager.h"
#include <unistd.h>
#include <iostream>

ICdatamanager::ICdatamanager() {
    // Initialize Runtime and Proxy
    runtime = CommonAPI::Runtime::get();
    ICProxy = runtime->buildProxy<v1_0::Moderator::ServiceManagerProxy>("local", "ServiceManager", "InstrumentCluster_Proxy");

    ICProxyInit();
}

ICdatamanager::~ICdatamanager(){

}

void ICdatamanager::ICProxyInit(){
    std::cout << "Checking ICProxy Availability!" << std::endl;
    while(!ICProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl; 

    ICProxy->getRpmAttribute().getChangedEvent().subscribe([this](const uint32_t& rpm){
        emit rpmChanged(rpm);
    });

    ICProxy->getSpeedAttribute().getChangedEvent().subscribe([this](const uint32_t& speed){
        emit speedChanged(speed);
    });
   
    ICProxy->getGearAttribute().getChangedEvent().subscribe([this](const std::string& gear){
        emit gearChanged(QString::fromStdString(gear));
    });
   
    
    ICProxy->getCurrentAttribute().getChangedEvent().subscribe([this](const float& current){
        emit currentChanged(current);
    });
   
    
    ICProxy->getPowerConsumptionAttribute().getChangedEvent().subscribe([this](const float& powerConsumption){
        emit powerConsumptionChanged(powerConsumption);
    });
   

    ICProxy->getVoltageAttribute().getChangedEvent().subscribe([this](const float voltage){
        emit voltageChanged(voltage);
    });
   

    ICProxy->getBatteryAttribute().getChangedEvent().subscribe([this](const uint8_t& battery){
        emit batteryChanged(battery);
    });
   

}

