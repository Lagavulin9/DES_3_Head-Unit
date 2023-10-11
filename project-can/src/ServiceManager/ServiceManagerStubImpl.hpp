#ifndef SERVICEMANAGERSTUBIMPL_HPP
#define SERVICEMANAGERSTUBIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/ServiceManagerStubDefault.hpp>
#include "ServiceManagerSender.hpp"

class ServiceManagerStubImpl : public v1_0::commonapi::ServiceManagerStubDefault {

private:
    ServiceManagerClass sender;

public:
    ServiceManagerStubImpl();
    virtual ~ServiceManagerStubImpl();

    virtual void setRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint32_t _receivedRpm, setRpmReply_t _return);
    virtual void setSpeed(const std::shared_ptr<CommonAPI::ClientId> _client, uint32_t _receivedSpeed, setSpeedReply_t _return); 

    
   
};

#endif  // SERVICEMANAGERSTUBIMPL_HPP
