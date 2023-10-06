#include "Can_Data_Register.hpp"

CanDataRegister::CanDataRegister() {
    runtime_ = CommonAPI::Runtime::get();
    proxy_ = runtime_->buildProxy<v1_0::commonapi::SpeedRpmProxy>("local", "seame02");
}

CanDataRegister::~CanDataRegister() {}

void CanDataRegister::sendDataToVSomeIP(double rpm, double speed) {
    CommonAPI::CallStatus callStatus;
    std::string message;  // 아마도 서버 응답을 받기 위한 메시지 변수가 필요할 것입니다.

    proxy_->setRpm(static_cast<uint16_t>(rpm), callStatus, message);
    if(callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "setRpm failed with status: " << static_cast<int>(callStatus) << " and message: " << message << std::endl;
    }

    proxy_->setSpeed(static_cast<uint16_t>(speed), callStatus, message);
    if(callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "setSpeed failed with status: " << static_cast<int>(callStatus) << " and message: " << message << std::endl;
    }
}