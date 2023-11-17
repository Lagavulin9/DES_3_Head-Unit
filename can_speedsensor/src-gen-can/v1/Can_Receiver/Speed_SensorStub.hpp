/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.0.v202012010850.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_CAN_RECEIVER_Speed__Sensor_STUB_HPP_
#define V1_CAN_RECEIVER_Speed__Sensor_STUB_HPP_

#include <functional>
#include <sstream>




#include <v1/Can_Receiver/Speed_Sensor.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif


#include <mutex>

#include <CommonAPI/Stub.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace Can_Receiver {

/**
 * Receives messages from remote and handles all dispatching of deserialized calls
 * to a stub for the service Speed_Sensor. Also provides means to send broadcasts
 * and attribute-changed-notifications of observable attributes as defined by this service.
 * An application developer should not need to bother with this class.
 */
class Speed_SensorStubAdapter
    : public virtual CommonAPI::StubAdapter,
      public virtual Speed_Sensor {
 public:
    ///Notifies all remote listeners about a change of value of the attribute speed.
    virtual void fireSpeedAttributeChanged(const uint32_t &speed) = 0;
    ///Notifies all remote listeners about a change of value of the attribute rpm.
    virtual void fireRpmAttributeChanged(const uint32_t &rpm) = 0;


    virtual void deactivateManagedInstances() = 0;

    void lockSpeedAttribute(bool _lockAccess) {
        if (_lockAccess) {
            speedMutex_.lock();
        } else {
            speedMutex_.unlock();
        }
    }
    void lockRpmAttribute(bool _lockAccess) {
        if (_lockAccess) {
            rpmMutex_.lock();
        } else {
            rpmMutex_.unlock();
        }
    }

protected:
    /**
     * Defines properties for storing the ClientIds of clients / proxies that have
     * subscribed to the selective broadcasts
     */
    std::recursive_mutex speedMutex_;
    std::recursive_mutex rpmMutex_;

};

/**
 * Defines the necessary callbacks to handle remote set events related to the attributes
 * defined in the IDL description for Speed_Sensor.
 * For each attribute two callbacks are defined:
 * - a verification callback that allows to verify the requested value and to prevent setting
 *   e.g. an invalid value ("onRemoteSet<AttributeName>").
 * - an action callback to do local work after the attribute value has been changed
 *   ("onRemote<AttributeName>Changed").
 *
 * This class and the one below are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class Speed_SensorStubRemoteEvent
{
public:
    virtual ~Speed_SensorStubRemoteEvent() { }

    /// Verification callback for remote set requests on the attribute speed
    virtual bool onRemoteSetSpeedAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, uint32_t _value) = 0;
    /// Action callback for remote set requests on the attribute speed
    virtual void onRemoteSpeedAttributeChanged() = 0;
    /// Verification callback for remote set requests on the attribute rpm
    virtual bool onRemoteSetRpmAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, uint32_t _value) = 0;
    /// Action callback for remote set requests on the attribute rpm
    virtual void onRemoteRpmAttributeChanged() = 0;
};

/**
 * Defines the interface that must be implemented by any class that should provide
 * the service Speed_Sensor to remote clients.
 * This class and the one above are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class Speed_SensorStub
    : public virtual CommonAPI::Stub<Speed_SensorStubAdapter, Speed_SensorStubRemoteEvent>
{
public:

    virtual ~Speed_SensorStub() {}
    void lockInterfaceVersionAttribute(bool _lockAccess) { static_cast<void>(_lockAccess); }
    bool hasElement(const uint32_t _id) const {
        return (_id < 2);
    }
    virtual const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> _client) = 0;

    /// Provides getter access to the attribute speed
    virtual const uint32_t &getSpeedAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) = 0;
    /// sets attribute with the given value and propagates it to the adapter
    virtual void fireSpeedAttributeChanged(uint32_t _value) {
    auto stubAdapter = CommonAPI::Stub<Speed_SensorStubAdapter, Speed_SensorStubRemoteEvent>::stubAdapter_.lock();
    if (stubAdapter)
        stubAdapter->fireSpeedAttributeChanged(_value);
    }
    void lockSpeedAttribute(bool _lockAccess) {
        auto stubAdapter = CommonAPI::Stub<Speed_SensorStubAdapter, Speed_SensorStubRemoteEvent>::stubAdapter_.lock();
        if (stubAdapter)
            stubAdapter->lockSpeedAttribute(_lockAccess);
    }
    /// Provides getter access to the attribute rpm
    virtual const uint32_t &getRpmAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) = 0;
    /// sets attribute with the given value and propagates it to the adapter
    virtual void fireRpmAttributeChanged(uint32_t _value) {
    auto stubAdapter = CommonAPI::Stub<Speed_SensorStubAdapter, Speed_SensorStubRemoteEvent>::stubAdapter_.lock();
    if (stubAdapter)
        stubAdapter->fireRpmAttributeChanged(_value);
    }
    void lockRpmAttribute(bool _lockAccess) {
        auto stubAdapter = CommonAPI::Stub<Speed_SensorStubAdapter, Speed_SensorStubRemoteEvent>::stubAdapter_.lock();
        if (stubAdapter)
            stubAdapter->lockRpmAttribute(_lockAccess);
    }


    using CommonAPI::Stub<Speed_SensorStubAdapter, Speed_SensorStubRemoteEvent>::initStubAdapter;
    typedef CommonAPI::Stub<Speed_SensorStubAdapter, Speed_SensorStubRemoteEvent>::StubAdapterType StubAdapterType;
    typedef CommonAPI::Stub<Speed_SensorStubAdapter, Speed_SensorStubRemoteEvent>::RemoteEventHandlerType RemoteEventHandlerType;
    typedef Speed_SensorStubRemoteEvent RemoteEventType;
    typedef Speed_Sensor StubInterface;
};

} // namespace Can_Receiver
} // namespace v1


// Compatibility
namespace v1_0 = v1;

#endif // V1_CAN_RECEIVER_Speed__Sensor_STUB_HPP_