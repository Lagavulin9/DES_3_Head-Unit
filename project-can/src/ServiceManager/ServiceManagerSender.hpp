#ifndef SERVICEMANAGERSENDER_HPP
#define SERVICEMANAGERSENDER_HPP


#include <string>
#include <CommonAPI/CommonAPI.hpp>



class ServiceManagerClass{
    public:
    ServiceManagerClass();
    ~ServiceManagerClass();

    std::shared_ptr<CommonAPI::Runtime> runtime;
    //Add Target Proxy


    CommonAPI::CallStatus callstatus;
    std::string returnMessage;
};


#endif //SERVICEMANAGERSENDER_HPP

