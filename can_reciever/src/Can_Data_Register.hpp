#ifndef CAN_DATA_REGISTER_HPP
#define CAN_DATA_REGISTER_HPP

#include <iostream>
#include <CommonAPI/CommonAPI.hpp>
#include "Speed_SensorStubImpl.hpp" 


using namespace v1_0::Can_Receiver;

class CanDataRegister {
public:
    CanDataRegister();
    virtual ~CanDataRegister();

    void sendDataToVSomeIP(uint32_t rpm, uint32_t speed); // Sends the data using Some/IP

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<Speed_SensorStubImpl> SpeedRpmService;

    void Speed_Sensor_Init();
    
};

#endif //CAN_DATA_REGISTER_HPP
