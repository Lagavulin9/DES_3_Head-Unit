#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <CommonAPI/CommonAPI.hpp>
#include "src-gen-car_control/v0/commonapi/Car_ControlProxy.hpp"

using namespace v0::commonapi;

int main()
{
    std::shared_ptr < CommonAPI::Runtime > runtime = CommonAPI::Runtime::get();

    std::string domain = "local";
    std::string instance = "commonapi.Car_Control";
    std::string connection = "client-Car_Control";
    std::shared_ptr<Car_ControlProxyDefault> myProxy = runtime->buildProxy<Car_ControlProxy>(domain, instance, connection);

    while (!myProxy->isAvailable()){
        usleep(10);
        std::cout << "Available..." << std::endl;
    }

    CommonAPI::CallStatus callStatus;
    std::string returnMessage;
    CommonAPI::CallInfo info(1000);
    info.sender_ = 1234;

    const char gears[] = {'P','R','N','D'};
    int arraySize = sizeof(gears) / sizeof(char);
    std::string gear;

    while (true) {
        gear = gears[rand() % arraySize];
        myProxy->setGear(gear,callStatus,returnMessage);
        if (callStatus != CommonAPI::CallStatus::SUCCESS) {
            std::cerr << "Remote call failed!\n";
            return -1;
        }
        std::cout << "Client recieved message: ’" << returnMessage << "’\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    return 0;
}