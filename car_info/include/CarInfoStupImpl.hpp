#ifndef CarControlStubImpl_H_
#define CarControlStubImpl_H_

#include <CommonAPI/CommonAPI.hpp>
#include "../src-gen-carcontrol/core/v0/commonapi/CarInfoStubDefault.hpp"

#include "PiRacer.hpp"
#include <Python.h>

class CarInfoStubImpl : public CarInfoStub {
    public: 
    CarInfoStubImpl();
    ~CarInfoStubImpl();
    void setBatteryStruct(float level_, float voltage_, float current_, float consumption_);
};
#endif //CarInfoStubImpl_H