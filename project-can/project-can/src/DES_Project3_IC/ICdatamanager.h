#ifndef ICDATAMANAGER_H
#define ICDATAMANAGER_H

#include <QObject>
#include <QString>
#include <cstdint>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/DES_Project3/ServiceManagerProxy.hpp>


class ICdatamanager : public QObject {
    Q_OBJECT

public:
    ICdatamanager();
    ~ICdatamanager();

signals:
    void rpmChanged(uint32_t rpm);
    void speedChanged(uint32_t speed);
    void gearChanged(QString gear);
    void currentChanged(float current);
    void powerConsumptionChanged(float powerConsumption);
    void voltageChanged(float voltage);
    void batteryChanged(uint8_t battery);

private:
    // Members
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<v1_0::DES_Project3::ServiceManagerProxy<>> ICProxy;

    void ICProxyInit();
};

#endif // ICDATAMANAGER_H
