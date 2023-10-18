#include "ICdataStubImpl.h"

ICdataStubImpl::ICdataStubImpl() {}

ICdataStubImpl::~ICdataStubImpl() {}

void ICdataStubImpl::setRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint32_t _filteredRpm, setRpmReply_t _return) {
    mDataManager.setRpm(_filteredRpm);
    _return("");
}

void ICdataStubImpl::setSpeed(const std::shared_ptr<CommonAPI::ClientId> _client, uint32_t _filteredSpeed, setSpeedReply_t _return) {
    mDataManager.setSpeed(_filteredSpeed);
    _return("");
}

void ICdataStubImpl::setGear(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _currentGear, setGearReply_t _return) {
    mDataManager.setGear(QString::fromStdString(_currentGear));
    _return("");
}

void ICdataStubImpl::setCurrent(const std::shared_ptr<CommonAPI::ClientId> _client, float _current, setCurrentReply_t _return) {
    mDataManager.setCurrent(_current);
    _return("");
}

void ICdataStubImpl::setPowerConsumption(const std::shared_ptr<CommonAPI::ClientId> _client, uint8_t _powerconsumption, setPowerConsumptionReply_t _return) {
    mDataManager.setPowerConsumption(_powerconsumption);
    _return("");
}

void ICdataStubImpl::setVoltage(const std::shared_ptr<CommonAPI::ClientId> _client, float _voltage, setVoltageReply_t _return) {
    mDataManager.setVoltage(_voltage);
    _return("");
}

void ICdataStubImpl::setBatteryLevel(const std::shared_ptr<CommonAPI::ClientId> _client, uint8_t _batterylevel, setBatteryLevelReply_t _return) {
    mDataManager.setBatteryLevel(_batterylevel);
    _return("");
}
