#include <iostream>
#include "ServiceManagerStubImpl.hpp"

ServiceManagerStubImpl::ServiceManagerStubImpl(){}

ServiceManagerStubImpl::~ServiceManagerStubImpl() {}

void ServiceManagerStubImpl::setRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint32_t _receivedRpm, setRpmReply_t _reply){
    //Add Target Proxy

    std::cout << "Received RPM: " << _receivedRpm << std::endl;


    _reply("");

    return;
}

void ServiceManagerStubImpl::setSpeed(const std::shared_ptr<CommonAPI::ClientId> _client, uint32_t _receivedSpeed, setSpeedReply_t _reply){
    //Add Target Proxy

    std::cout << "Received Speed: " << _receivedSpeed << std::endl;

    _reply("");

    return;
}

