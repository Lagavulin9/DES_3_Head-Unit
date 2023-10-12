#ifndef CAN_DATA_REGISTER_HPP
#define CAN_DATA_REGISTER_HPP

#include <iostream>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/ServiceManagerProxy.hpp>

class CanDataRegister {
public:
    CanDataRegister();
    virtual ~CanDataRegister();

    void sendDataToVSomeIP(uint32_t rpm, uint32_t speed);

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<v1_0::commonapi::ServiceManagerProxy<>> SpeedRpmProxy;
   
};

#endif //CAN_DATA_REGISTER_HPP
