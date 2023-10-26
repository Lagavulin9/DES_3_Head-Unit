// #include <CommonAPI/CommonAPI.hpp>

// #include "ServiceManagerStubImpl.hpp"
#include "ServiceManagerReceiver.hpp"
#include <thread>
#include <unistd.h>

int main() { 
    ServiceManagerReceiver SMR = ServiceManagerReceiver();

    // auto runtime = CommonAPI::Runtime::get();
    // auto ServiceManagerService = std::make_shared<ServiceManagerStubImpl>();

    // while(!runtime->registerService("local", "ServiceManager", ServiceManagerService, "ServiceManager_Service")){
    //     std::cout << "Register ServiceManager Service failed, trying again in 100 milliseconds..." << std::endl;
    //     std::this_thread::sleep_for(std::chrono::milliseconds(100));
    // }
    // std::cout << "Successfully Registered ServiceManager Service!" << std::endl;

    while (1) {
        sleep(100);
    }

    return 0;  
}
