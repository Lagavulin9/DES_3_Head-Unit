#include "ServiceManagerStubImpl.hpp"

ServiceManagerStubImpl::ServiceManagerStubImpl() { }
ServiceManagerStubImpl::~ServiceManagerStubImpl() { }

void ServiceManagerStubImpl::setRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _rpm, setRpmReply_t _reply) {
    std::cout << "********************" << std::endl;
    std::cout << "Rpm: " << _rpm << std::endl;
    std::cout << "********************" << std::endl;

    
}

void ServiceManagerStubImpl::setSpeed(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _speed, setSpeedReply_t _reply) {
    std::cout << "********************" << std::endl;
    std::cout << "Speed: " << _speed << std::endl;
    std::cout << "********************" << std::endl;

   
}
