#include "CarInfoStubImpl.hpp"


CarInfoStubImpl::CarInfoStubImpl() {
}

CarInfoStubImpl::~CarInfoStubImpl() {
}

void CarInfoStubImpl::setBatteryStruct(float level_, float voltage_, float current_, float consumption_) {
    v0::commonapi::CommonTypes::batteryStruct battery;
    battery.setLevel(level_);
    battery.setVoltage(voltage_);
    battery.setCurrent(current_);
    battery.setConsumption(consumption_);
    setBatteryAttribute(battery);
}