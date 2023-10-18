#include <CommonAPI/CommonAPI.hpp>
#include "ServiceManagerStubImpl.hpp"


using namespace v1::DES_Project3;

int main() {
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<ServiceManagerStubImpl> serviceManager;

    runtime = CommonAPI::Runtime::get();
    serviceManager = std::make_shared<ServiceManagerStubImpl>();
    runtime -> registerService ("local", "ServiceManager", serviceManager);

    while(1) { }

    return 0;  
}

 