#ifndef SERVICEMANAGERSENDER_HPP
#define SERVICEMANAGERSENDER_HPP

#include <string>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/DES_Project3/ICProxy.hpp>

class ServiceManagerSender {
public:
    ServiceManagerSender();
    ~ServiceManagerSender();

    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<v1::DES_Project3::ICProxy<>> ICProxy;

    CommonAPI::CallStatus callStatus;
    std::string returnMessage;
};

#endif //SERVICEMANAGERSENDER_HPP
