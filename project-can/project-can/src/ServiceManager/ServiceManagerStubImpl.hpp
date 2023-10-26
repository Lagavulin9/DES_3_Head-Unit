#ifndef SERVICEMANAGERSTUBIMPL_HPP
#define SERVICEMANAGERSTUBIMPL_HPP

// Include necessary headers for CommonAPI
#include <CommonAPI/CommonAPI.hpp>
#include <v1/DES_Project3/ServiceManagerStubDefault.hpp>

class ServiceManagerStubImpl: public v1_0::DES_Project3::ServiceManagerStubDefault
{
public:
    ServiceManagerStubImpl();
    virtual ~ServiceManagerStubImpl();
};

#endif // SERVICEMANAGERSTUBIMPL_HPP
