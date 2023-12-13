/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.14.v202310241606.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#include <v0/commonapi/SpeedSensorSomeIPProxy.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v0 {
namespace commonapi {

std::shared_ptr<CommonAPI::SomeIP::Proxy> createSpeedSensorSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection) {
    return std::make_shared< SpeedSensorSomeIPProxy>(_address, _connection);
}

void initializeSpeedSensorSomeIPProxy() {
    CommonAPI::SomeIP::AddressTranslator::get()->insert(
        "local:commonapi.SpeedSensor:v0_1:SpeedSensor",
        0x3000, 0x55f0, 0, 1);
    CommonAPI::SomeIP::Factory::get()->registerProxyCreateMethod(
        "commonapi.SpeedSensor:v0_1",
        &createSpeedSensorSomeIPProxy);
}

INITIALIZER(registerSpeedSensorSomeIPProxy) {
    CommonAPI::SomeIP::Factory::get()->registerInterface(initializeSpeedSensorSomeIPProxy);
}

SpeedSensorSomeIPProxy::SpeedSensorSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection)
        : CommonAPI::SomeIP::Proxy(_address, _connection),
          speed_(*this, CommonAPI::SomeIP::eventgroup_id_t(0x8150), CommonAPI::SomeIP::event_id_t(0x8150), CommonAPI::SomeIP::method_id_t(0x3101), true, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE, false, CommonAPI::SomeIP::method_id_t(0x3102), true, static_cast< CommonAPI::SomeIP::IntegerDeployment<uint32_t>* >(nullptr)),
          rpm_(*this, CommonAPI::SomeIP::eventgroup_id_t(0x81b4), CommonAPI::SomeIP::event_id_t(0x81b4), CommonAPI::SomeIP::method_id_t(0x3201), true, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE, false, CommonAPI::SomeIP::method_id_t(0x3202), true, static_cast< CommonAPI::SomeIP::IntegerDeployment<uint32_t>* >(nullptr))
{
}

SpeedSensorSomeIPProxy::~SpeedSensorSomeIPProxy() {
}

SpeedSensorSomeIPProxy::SpeedAttribute& SpeedSensorSomeIPProxy::getSpeedAttribute() {
    return speed_;
}
SpeedSensorSomeIPProxy::RpmAttribute& SpeedSensorSomeIPProxy::getRpmAttribute() {
    return rpm_;
}


void SpeedSensorSomeIPProxy::getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const {
    ownVersionMajor = 0;
    ownVersionMinor = 1;
}

std::future<void> SpeedSensorSomeIPProxy::getCompletionFuture() {
    return CommonAPI::SomeIP::Proxy::getCompletionFuture();
}

} // namespace commonapi
} // namespace v0