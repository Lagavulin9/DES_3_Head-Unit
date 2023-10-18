#include <iostream>
#include "ServiceManagerStubImpl.hpp"

ServiceManagerStubImpl::ServiceManagerStubImpl() :sender() {}

ServiceManagerStubImpl::~ServiceManagerStubImpl() {}

void ServiceManagerStubImpl::setRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint32_t _receivedRpm, setRpmReply_t _reply) {
    sender.ICProxy->setRpm(_receivedRpm, sender.callStatus, sender.returnMessage);
    _reply("");
}

void ServiceManagerStubImpl::setSpeed(const std::shared_ptr<CommonAPI::ClientId> _client, uint32_t _receivedSpeed, setSpeedReply_t _reply) {
    sender.ICProxy->setSpeed(_receivedSpeed, sender.callStatus, sender.returnMessage);
    _reply("");
}
