#include "ServiceManagerSender.hpp"



ServiceManagerClass::ServiceManagerClass(){
    runtime =CommonAPI::Runtime::get();

    //TargetProxy = runtime->buildProxy<TargetProxy>("local", "Proxyname");
}


ServiceManagerClass::~ServiceManagerClass(){ }

