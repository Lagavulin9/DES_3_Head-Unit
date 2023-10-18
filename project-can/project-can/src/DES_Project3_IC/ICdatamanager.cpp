#include "ICdatamanager.h"

ICdatamanager::ICdatamanager(QObject *parent) : QObject(parent), m_rpm(0), m_speed(0), m_gear("P"),
m_current(0.0f), m_powerConsumption(0), m_voltage(0.0f), m_batteryLevel(0) {}


// RPM
uint32_t ICdatamanager::getRpm() const {
    return m_rpm;
}

void ICdatamanager::setRpm(uint32_t rpm) {
    if (ICProxy && ICProxy->isAvailable()) {
        CommonAPI::CallStatus callStatus;
        std::string message;
        ICProxy->setRpm(rpm, callStatus, message);
        if (callStatus == CommonAPI::CallStatus::SUCCESS && m_rpm != rpm) {
            m_rpm = rpm;
            emit rpmChanged();
        }
    }
}

// Speed
uint32_t ICdatamanager::getSpeed() const {
    return m_speed;
}

void ICdatamanager::setSpeed(uint32_t speed) {
    if (ICProxy && ICProxy->isAvailable()) {
        CommonAPI::CallStatus callStatus;
        std::string message;
        ICProxy->setSpeed(speed, callStatus, message);
        if (callStatus == CommonAPI::CallStatus::SUCCESS && m_speed != speed) {
            m_speed = speed;
            emit speedChanged();
        }
    }
}

// Gear
QString ICdatamanager::getGear() const {
    return m_gear;
}

void ICdatamanager::setGear(const QString &gear) {
    if (ICProxy && ICProxy->isAvailable()) {
        CommonAPI::CallStatus callStatus;
        std::string message;
        ICProxy->setGear(gear.toStdString(), callStatus, message);
        if (callStatus == CommonAPI::CallStatus::SUCCESS && m_gear != gear) {
            m_gear = gear;
            emit gearChanged();
        }
    }
}

// Current
float ICdatamanager::getCurrent() const {
    return m_current;
}

void ICdatamanager::setCurrent(float current) {
    if (ICProxy && ICProxy->isAvailable()) {
        CommonAPI::CallStatus callStatus;
        std::string message;
        ICProxy->setCurrent(current, callStatus, message);
        if (callStatus == CommonAPI::CallStatus::SUCCESS && m_current != current) {
            m_current = current;
            emit currentChanged();
        }
    }
}

// Power Consumption
uint8_t ICdatamanager::getPowerConsumption() const {
    return m_powerConsumption;
}

void ICdatamanager::setPowerConsumption(uint8_t powerConsumption) {
    if (ICProxy && ICProxy->isAvailable()) {
        CommonAPI::CallStatus callStatus;
        std::string message;
        ICProxy->setPowerConsumption(powerConsumption, callStatus, message);
        if (callStatus == CommonAPI::CallStatus::SUCCESS && m_powerConsumption != powerConsumption) {
            m_powerConsumption = powerConsumption;
            emit powerConsumptionChanged();
        }
    }
}

// Voltage
float ICdatamanager::getVoltage() const {
    return m_voltage;
}

void ICdatamanager::setVoltage(float voltage) {
    if (ICProxy && ICProxy->isAvailable()) {
        CommonAPI::CallStatus callStatus;
        std::string message;
        ICProxy->setVoltage(voltage, callStatus, message);
        if (callStatus == CommonAPI::CallStatus::SUCCESS && m_voltage != voltage) {
            m_voltage = voltage;
            emit voltageChanged();
        }
    }
}

// Battery Level
uint8_t ICdatamanager::getBatteryLevel() const {
    return m_batteryLevel;
}

void ICdatamanager::setBatteryLevel(uint8_t batteryLevel) {
    if (ICProxy && ICProxy->isAvailable()) {
        CommonAPI::CallStatus callStatus;
        std::string message;
        ICProxy->setBatteryLevel(batteryLevel, callStatus, message);
        if (callStatus == CommonAPI::CallStatus::SUCCESS && m_batteryLevel != batteryLevel) {
            m_batteryLevel = batteryLevel;
            emit batteryLevelChanged();
        }
    }
}
