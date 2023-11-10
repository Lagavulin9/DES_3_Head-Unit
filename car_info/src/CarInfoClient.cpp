#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <CommonAPI/CommonAPI.hpp>
#include "../src-gen-carinfo/core/v0/commonapi/CarInfoProxy.hpp"
#include "../src-gen-carinfo/core/v0/commonapi/CommonTypes.hpp"

int main(){
    /* Create Proxy */
    std::shared_ptr < CommonAPI::Runtime > runtime = CommonAPI::Runtime::get();
    std::string domain      = "local";
    std::string instance    = "commonapi.CarInfo";
    std::string connection  = "service-CarInfo";
    auto myProxy = runtime->buildProxy<v0::commonapi::CarInfoProxyCar>(domain, instance, connection);
    //auto myProxy = runtime->buildProxyWithDefaultAttributeExtension<E08CrcProtectionProxy, CommonAPI::Extensions::AttributeCacheExtension>(domain, instance, connection);
    std::cout << "Waiting for service to become available." << std::endl;
    while (!myProxy->isAvailable()){
        std::this_thread::sleep_for(std::chrono::microseconds(10));
    }

    /* Subscribe */
    CommonAPI::CallStatus callStatus;
    CommonAPI::CallInfo info(1000);
    info.sender_ = 1234;
    // Battery Info 
    CommonTypes::batteryStruct battery;
    myProxy->getBatteryAttribute().getChangedEvent().subscribe(
        [&](const CommonTypes::batteryStruct& val)
        {
            std::cout << " ---------------------------" << std::endl
            << "Received change message for battery"    << std::endl
            << "  level     : " << val.getLevel()       << std::endl
            << "  voltage   : " << val.getVoltage()     << std::endl
            << "  current   : " << val.getCurrent()     << std::endl
            << "  consuption: " << val.getConsumption() << std::endl
            << " ---------------------------" << std::endl;
        }
    );
    
    while (true) {
        // wait for a second
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
