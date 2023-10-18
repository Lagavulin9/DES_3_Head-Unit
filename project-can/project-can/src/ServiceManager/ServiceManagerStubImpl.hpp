#ifndef SERVICEMANAGERSTUBIMPL_HPP
#define SERVICEMANAGERSTUBIMPL_HPP

#include <string>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/DES_Project3/ServiceManagerStubDefault.hpp>

#include "ServiceManagerSender.hpp"

class ServiceManagerStubImpl : public v1::DES_Project3::ServiceManagerStubDefault {

private:
    ServiceManagerSender sender;

public:
    ServiceManagerStubImpl();
    virtual ~ServiceManagerStubImpl();

    virtual void setRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint32_t _receivedRpm, setRpmReply_t _return) override;
    virtual void setSpeed(const std::shared_ptr<CommonAPI::ClientId> _client, uint32_t _receivedSpeed, setSpeedReply_t _return) override; 

    
   
};

#endif  // SERVICEMANAGERSTUBIMPL_HPP
