#ifndef SPEED_SENSORSTUBIMPL_HPP
#define SPEED_SENSORSTUBIMPL_HPP

// Include necessary headers for CommonAPI
#include <CommonAPI/CommonAPI.hpp>
#include <v0/commonapi/SpeedSensorStubDefault.hpp>

class SpeedSensorStubImpl: public v0_1::commonapi::SpeedSensorStubDefault
{
public:
    SpeedSensorStubImpl();
    virtual ~SpeedSensorStubImpl();
};

#endif // SPEED_SENSORSTUBIMPL_HPP
