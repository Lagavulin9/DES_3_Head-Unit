#include <CommonAPI/CommonAPI.hpp>
#include "ServiceManagerStubImpl.hpp"


using namespace v1_0::commonapi;

int main() {
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<ServiceManagerStubImpl> ServiceManager;

    runtime = CommonAPI::Runtime::get();
    ServiceManager = std::make_shared<ServiceManagerStubImpl>();
    runtime -> registerService ("local", "ServiceManager", ServiceManager);

    while(1) { }

    return 0;  
}

 