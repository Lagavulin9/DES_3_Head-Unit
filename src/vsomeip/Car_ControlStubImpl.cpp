#include "Car_ControlStubImpl.hpp"

Car_ControlStubImpl::Car_ControlStubImpl() {
}

Car_ControlStubImpl::~Car_ControlStubImpl() {
}

void Car_ControlStubImpl::setGear(const std::shared_ptr<CommonAPI::ClientId> _client,
        std::string _gear,
        setGearReply_t _reply) {

    std::stringstream messageStream;

    messageStream << "Gear: " << _gear << "!";
    std::cout << "setGear('" << _gear << "'): '" << messageStream.str() << "'\n";

    _reply(messageStream.str());
};