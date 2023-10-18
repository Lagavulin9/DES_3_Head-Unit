#ifndef CAN_DATA_REGISTER_HPP
#define CAN_DATA_REGISTER_HPP

#include <iostream>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/DES_Project3/ServiceManagerProxy.hpp>

class CanDataRegister {
public:
    CanDataRegister();
    virtual ~CanDataRegister();

    void sendDataToVSomeIP(uint32_t rpm, uint32_t speed);

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<v1::DES_Project3::ServiceManagerProxy<>> SpeedRpmProxy;
};

#endif //CAN_DATA_REGISTER_HPP
