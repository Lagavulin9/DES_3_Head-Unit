#ifndef SPEED_SENSORSTUBIMPL_HPP
#define SPEED_SENSORSTUBIMPL_HPP

// Include necessary headers for CommonAPI
#include <CommonAPI/CommonAPI.hpp>
#include <v1/Can_Receiver/Speed_SensorStubDefault.hpp>

class Speed_SensorStubImpl: public v1_0::Can_Receiver::Speed_SensorStubDefault
{
public:
    Speed_SensorStubImpl();
    virtual ~Speed_SensorStubImpl();
};

#endif // SPEED_SENSORSTUBIMPL_HPP
