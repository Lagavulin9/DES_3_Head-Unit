#ifndef SERVICEMANAGERSTUBIMPL_HPP
#define SERVICEMANAGERSTUBIMPL_HPP

// Include necessary headers for CommonAPI
#include <CommonAPI/CommonAPI.hpp>
#include <v1/Moderator/ServiceManagerStubDefault.hpp>

class ServiceManagerStubImpl: public v1_0::Moderator::ServiceManagerStubDefault
{
public:
    ServiceManagerStubImpl();
    virtual ~ServiceManagerStubImpl();
};

#endif // SERVICEMANAGERSTUBIMPL_HPP
