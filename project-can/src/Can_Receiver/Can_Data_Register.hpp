#ifndef CAN_DATA_REGISTER_HPP
#define CAN_DATA_REGISTER_HPP

#include <iostream>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/SpeedRpmStubDefault.hpp>
#include <v1/commonapi/SpeedRpmProxy.hpp>

class CanDataRegister {
public:
    CanDataRegister();
    virtual ~CanDataRegister();
    void sendDataToVSomeIP(double rpm, double speed);

private:
    std::shared_ptr<CommonAPI::Runtime> runtime_;
    std::shared_ptr<v1_0::commonapi::SpeedRpmProxy<>> proxy_;
};

#endif //CAN_DATA_REGISTER_HPP
