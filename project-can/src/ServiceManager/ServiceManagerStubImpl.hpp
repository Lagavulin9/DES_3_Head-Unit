#ifndef SERVICEMANAGERSTUBIMPL_HPP
#define SERVICEMANAGERSTUBIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/SpeedRpmStubDefault.hpp>

class ServiceManagerStubImpl : public v1_0::commonapi::SpeedRpmStubDefault {
public:
    ServiceManagerStubImpl();
    virtual ~ServiceManagerStubImpl();
    virtual void setRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _rpm, setRpmReply_t _return);
    virtual void setSpeed(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _speed, setSpeedReply_t _return);
};

#endif
