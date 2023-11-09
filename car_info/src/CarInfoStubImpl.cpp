#include "CarInfoStubImpl.hpp"

CarInfoStubImpl::CarInfoStubImpl() {
}

CarInfoStubImpl::~CarInfoStubImpl() {
}

void CarInfoStubImpl::setBatteryStruct(float level_, float voltage_, float current_, float consumption_) {
    level->setContent(level_);
    voltage->setContent(voltage_);
    current->setContent(current_);
    consumption->setContent(consumption_);
}