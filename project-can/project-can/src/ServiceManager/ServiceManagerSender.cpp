#include "ServiceManagerSender.hpp"

ServiceManagerSender::ServiceManagerSender() {
    runtime = CommonAPI::Runtime::get();
    ICProxy = runtime->buildProxy<v1::DES_Project3::ICProxy>("local", "IC");
}

ServiceManagerSender::~ServiceManagerSender() { }
