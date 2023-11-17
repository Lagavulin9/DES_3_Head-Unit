#include "Can_Data_Register.hpp"

CanDataRegister::CanDataRegister() {
    runtime = CommonAPI::Runtime::get();
    SpeedRpmProxy = runtime->buildProxy<v1_0::commonapi::ServiceManagerProxy>("local", "ServiceManager");

}

CanDataRegister::~CanDataRegister() {
}

void CanDataRegister::sendDataToVSomeIP(uint32_t rpm, uint32_t speed) {
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;


    std::shared_ptr<CommonAPI::CallInfo> callInfo = std::make_shared<CommonAPI::CallInfo>();
    
    
    SpeedRpmProxy->setRpm(rpm, callStatus, returnMessage, nullptr);
    if(callStatus != CommonAPI::CallStatus::SUCCESS){
        std::cerr << "Error: Failed to set RPM" << std::endl;
    }
    SpeedRpmProxy->setSpeed(speed, callStatus, returnMessage, nullptr);
    if(callStatus != CommonAPI::CallStatus::SUCCESS){
        std::cerr << "Error: Failed to set Speed" << std::endl;
    }
}
