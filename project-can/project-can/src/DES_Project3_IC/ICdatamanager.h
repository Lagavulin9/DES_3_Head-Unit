#ifndef ICDATAMANAGER_H
#define ICDATAMANAGER_H

#include <QObject>
#include <QString>
#include <cstdint> // for uint32_t and uint8_t
#include <CommonAPI/CommonAPI.hpp>
#include <v1/DES_Project3/ICProxy.hpp>


class ICdatamanager : public QObject {
    Q_OBJECT

    // Properties
    Q_PROPERTY(uint32_t rpm READ getRpm WRITE setRpm NOTIFY rpmChanged) 
    Q_PROPERTY(uint32_t speed READ getSpeed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(QString gear READ getGear WRITE setGear NOTIFY gearChanged)
    Q_PROPERTY(float current READ getCurrent WRITE setCurrent NOTIFY currentChanged)
    Q_PROPERTY(uint8_t powerConsumption READ getPowerConsumption WRITE setPowerConsumption NOTIFY powerConsumptionChanged)
    Q_PROPERTY(float voltage READ getVoltage WRITE setVoltage NOTIFY voltageChanged)
    Q_PROPERTY(uint8_t batteryLevel READ getBatteryLevel WRITE setBatteryLevel NOTIFY batteryLevelChanged)

public:
    explicit ICdatamanager(QObject *parent = nullptr);

    // RPM
    uint32_t getRpm() const;
    void setRpm(uint32_t rpm);

    // Speed
    uint32_t getSpeed() const;
    void setSpeed(uint32_t speed);

    // Gear
    QString getGear() const;
    void setGear(const QString &gear);

    // Current
    float getCurrent() const;
    void setCurrent(float current);

    // Power Consumption
    uint8_t getPowerConsumption() const;
    void setPowerConsumption(uint8_t powerConsumption);

    // Voltage
    float getVoltage() const;
    void setVoltage(float voltage);

    // Battery Level
    uint8_t getBatteryLevel() const;
    void setBatteryLevel(uint8_t batteryLevel);

signals:
    void rpmChanged();
    void speedChanged();
    void gearChanged();
    void currentChanged();
    void powerConsumptionChanged();
    void voltageChanged();
    void batteryLevelChanged();

private:
    uint32_t m_rpm;
    uint32_t m_speed;
    QString m_gear;
    float m_current;
    uint8_t m_powerConsumption;
    float m_voltage;
    uint8_t m_batteryLevel;

    std::shared_ptr<v1::DES_Project3::ICProxy<>> ICProxy;
};

#endif // ICDATAMANAGER_H
