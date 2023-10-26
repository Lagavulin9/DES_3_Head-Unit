#ifndef SERVICE_MANAGER_RECEIVER_HPP
#define SERVICE_MANAGER_RECEIVER_HPP

#include <CommonAPI/CommonAPI.hpp>
#include "ServiceManagerStubImpl.hpp"
#include <v1/Can_Receiver/Speed_SensorProxy.hpp>
// #include <v1/DES_Project3/Car_InformationProxy.hpp>
// #include <v1/DES_Project3/Car_ControlProxy.hpp>
// #include <v1/DES_Project3/HUProxy.hpp>

class ServiceManagerReceiver {
public:
    ServiceManagerReceiver();
    ~ServiceManagerReceiver();


private:
    std::shared_ptr<CommonAPI::Runtime> runtime;

    std::shared_ptr<ServiceManagerStubImpl> ServiceManagerService;

    std::shared_ptr<v1_0::Can_Receiver::Speed_SensorProxy<>> SpeedRpmProxy;
    // std::shared_ptr<v1_0::DES_Project3::Car_InformationProxy<>> CarInfoProxy;
    // std::shared_ptr<v1_0::DES_Project3::Car_ControlProxy<>> CarControlProxy;
    // std::shared_ptr<v1_0::DES_Project3::HUProxy<>> HUProxy;

    void SpeedProxyInit();
    // void CarInfoProxyInit();
    // void CarControlProxyInit();
    // void HUProxyInit();

    std::string gear;

   

};

#endif //SERVICE_MANAGER_RECEIVER_HPP

