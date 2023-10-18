/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#include <v1/DES_Project3/ServiceManagerSomeIPStubAdapter.hpp>
#include <v1/DES_Project3/ServiceManager.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace DES_Project3 {

std::shared_ptr<CommonAPI::SomeIP::StubAdapter> createServiceManagerSomeIPStubAdapter(
                   const CommonAPI::SomeIP::Address &_address,
                   const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
                   const std::shared_ptr<CommonAPI::StubBase> &_stub) {
    return std::make_shared< ServiceManagerSomeIPStubAdapter<::v1::DES_Project3::ServiceManagerStub>>(_address, _connection, _stub);
}

void initializeServiceManagerSomeIPStubAdapter() {
    CommonAPI::SomeIP::AddressTranslator::get()->insert(
        "local:DES_Project3.ServiceManager:v1_0:ServiceManager",
         0x1000, 0x1001, 1, 0);
    CommonAPI::SomeIP::Factory::get()->registerStubAdapterCreateMethod(
        "DES_Project3.ServiceManager:v1_0",
        &createServiceManagerSomeIPStubAdapter);
}

INITIALIZER(registerServiceManagerSomeIPStubAdapter) {
    CommonAPI::SomeIP::Factory::get()->registerInterface(initializeServiceManagerSomeIPStubAdapter);
}

} // namespace DES_Project3
} // namespace v1
