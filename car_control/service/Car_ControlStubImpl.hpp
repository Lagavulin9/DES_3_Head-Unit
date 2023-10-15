#ifndef Car_ControlStubImpl_H_
#define Car_ControlStubImpl_H_

#include <CommonAPI/CommonAPI.hpp>
#include "../src-gen-car_control/v0/commonapi/Car_ControlStubDefault.hpp"

class Car_ControlStubImpl: public v0_1::commonapi::Car_ControlStubDefault {

public:
    Car_ControlStubImpl();
    virtual ~Car_ControlStubImpl();
    virtual void setGear(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _gear, setGearReply_t _return);
};

#endif 