#ifndef CAN_DATA_REGISTER_HPP
#define CAN_DATA_REGISTER_HPP

#include <iostream>
#include <CommonAPI/CommonAPI.hpp>
#include "SpeedSensorStubImpl.hpp" 


using namespace v0_1::commonapi;

class CanDataRegister {
public:
    CanDataRegister();
    virtual ~CanDataRegister();

    void sendDataToVSomeIP(uint32_t rpm, uint32_t speed); // Sends the data using Some/IP

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<SpeedSensorStubImpl> SpeedRpmService;

    void SpeedSensor_Init();
    
};

#endif //CAN_DATA_REGISTER_HPP
