#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>

#include "ServiceManagerStubImpl.hpp"


int main() {
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    std::shared_ptr<ServiceManagerStubImpl> myService = std::make_shared<ServiceManagerStubImpl>();
    if(runtime -> registerService("local", "seame02", myService)){
        std::cout << "Service registered." << std::endl;
    }else{
        std::cout<<"Service not registered." << std::endl;
    }
    std::cout << "Successfully Registered Service!" << std::endl;

   // runtime->registerService("local", "seame02", myService);

    while (true) {
        std::cout << "Waiting for calls...(Abort with CTRL+C)" <<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(30));
    }

    return 0;
}
