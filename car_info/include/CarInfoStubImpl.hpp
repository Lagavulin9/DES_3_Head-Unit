#ifndef CarInfoStubImpl_H_
#define CarInfoStubImpl_H_

#include <CommonAPI/CommonAPI.hpp>
#include "../src-gen/core/v0/commonapi/CarInfoStubDefault.hpp"
#include "../src-gen/core/v0/commonapi/CommonTypes.hpp"

#include "PiRacer.hpp"
#include <Python.h>

class CarInfoStubImpl: public v0::commonapi::CarInfoStubDefault {
    public: 
        CarInfoStubImpl();
        ~CarInfoStubImpl();
        void setBatteryStruct(float level_, float voltage_, float current_, float consumption_);
};
#endif //CarInfoStubImpl_H