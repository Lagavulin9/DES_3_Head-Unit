#include <iostream>
#include <thread>

#include <CommonAPI/CommonAPI.hpp>
#include "Car_ControlStubImpl.hpp"

using namespace std;

int main() {

    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();

    std::string domain      = "local";
    std::string instance    = "commonapi.Car_Control";
    std::string connection  = "service-Car_Control";

    std::shared_ptr<Car_ControlStubImpl> myService = std::make_shared<Car_ControlStubImpl>();
    bool successfullyRegistered = runtime->registerService(domain, instance, myService, connection);

    while (!successfullyRegistered) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        successfullyRegistered = runtime->registerService(domain, instance, myService, connection);
    }

    std::cout << "Successfully Registered Service!" << std::endl;

    while (true) {
        std::cout << "Waiting for calls... (Abort with CTRL+C)" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(60));
    }

    return 0;
}