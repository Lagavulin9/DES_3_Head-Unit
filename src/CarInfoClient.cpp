#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>

#include <CommonAPI/CommonAPI.hpp>
#include "../src-gen/core/v0/commonapi/CarInfoProxy.hpp"
#include "../src-gen/core/v0/commonapi/CommonTypes.hpp"

int main(){
    /* Create Proxy */
    std::shared_ptr < CommonAPI::Runtime > runtime = CommonAPI::Runtime::get();
    std::string domain      = "local";
    std::string instance    = "commonapi.CarInfo";
    std::string connection  = "service-CarInfo";
    auto myProxy = runtime->buildProxy<v0::commonapi::CarInfoProxy>(domain, instance, connection);
    std::cout << "Waiting for service to become available." << std::endl;
    while (!myProxy->isAvailable()){
        std::this_thread::sleep_for(std::chrono::microseconds(10));
    }

    /* Subscribe */
    CommonAPI::CallStatus callStatus;
    CommonAPI::CallInfo info(1000);
    info.sender_ = 1234;

    // Battery Info 
    v0::commonapi::CommonTypes::batteryStruct battery;
    myProxy->getBatteryAttribute().getChangedEvent().subscribe(
        [&](const v0::commonapi::CommonTypes::batteryStruct& val) {
            std::cout << " ---------------------------"             << std::endl 
                      << "Received change message for battery"      << std::endl 
                      << "\tlevel     : " << val.getLevel()         << std::endl 
                      << "\tvoltage   : " << val.getVoltage()       << std::endl 
                      << "\tcurrent   : " << val.getCurrent()       << std::endl 
                      << "\tconsuption: " << val.getConsumption()   << std::endl 
                      << " ---------------------------" << std::endl;
        }, 
        [&](const CommonAPI::CallStatus &status) {
            if (status == CommonAPI::CallStatus::INVALID_VALUE) {
                std::cout << "Subscription (Changed Event) of battery attribute returned CallStatus==INVALID_VALUE" << std::endl;
                // do something... (no eventhandler gets called in case of INVALID_VALUE status) 
            } else  if (status == CommonAPI::CallStatus::SUCCESS) {
                std::cout << "Got valid response for battery Async getter" << std::endl;
            }
        }
    );

    while (true) {
        // wait for a second
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;

}
