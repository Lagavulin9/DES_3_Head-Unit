#ifndef ICSTUBIMPL_H
#define ICSTUBIMPL_H

#include <string>
#include <QString>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/DES_Project3/ICStubDefault.hpp>
#include "ICdatamanager.h"

class ICdataStubImpl : public v1::DES_Project3::ICStubDefault {
private:
    ICdatamanager mDataManager; 

public:
    ICdataStubImpl();
    virtual ~ICdataStubImpl();

    virtual void setRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint32_t _filteredRpm, setRpmReply_t _return);
    virtual void setSpeed(const std::shared_ptr<CommonAPI::ClientId> _client, uint32_t _filteredSpeed, setSpeedReply_t _return);
    virtual void setGear(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _currentGear, setGearReply_t _return);
    virtual void setCurrent(const std::shared_ptr<CommonAPI::ClientId> _client, float _current, setCurrentReply_t _return);
    virtual void setPowerConsumption(const std::shared_ptr<CommonAPI::ClientId> _client, uint8_t _powerconsumption, setPowerConsumptionReply_t _return);
    virtual void setVoltage(const std::shared_ptr<CommonAPI::ClientId> _client, float _voltage, setVoltageReply_t _return);
    virtual void setBatteryLevel(const std::shared_ptr<CommonAPI::ClientId> _client, uint8_t _batterylevel, setBatteryLevelReply_t _return);
};

#endif  // ICSTUBIMPL.H
