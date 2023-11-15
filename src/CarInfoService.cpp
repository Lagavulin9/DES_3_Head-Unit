/*includes*/
#include <CommonAPI/CommonAPI.hpp>
#include "CarInfoStubImpl.hpp"
#include "PiRacer.hpp"
#include <iostream>
#include <chrono>
#include <csignal>
#include <cstdlib>
#include <vector>
#include <unistd.h>
#include <Python.h>

/* signal handler */
void signalHandler(int signum)
{
	std::cout << "\n signal: " << signum << std::endl;
	std::cout << "Shutting down..." << std::endl;
	exit(128 + signum);
}

/* clean up */
void cleanUp()
{
    // delete singeltons
	PiRacer* piracer = PiRacer::getInstance();
	piracer->deleteInstance();
    // finalize python interpreter
	Py_Finalize();
	std::cout << "cleanUp(): Python Interpreter Finalized." << std::endl;
}

/*main*/
int main() { 
    /*runtime setups*/
    // signal handler
    signal(SIGINT, signalHandler);
	signal(SIGQUIT, signalHandler);
    // python interpreter
	setenv("PYTHONPATH", "../piracer", 0);
	Py_Initialize();
	atexit(cleanUp);

    /*create singelton piracer */
	PiRacer* piracer = PiRacer::getInstance();

    /*setup CommonAPI service*/
    // get runtime
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    // define service's domain, instance, connection
    std::string domain      = "local";
    std::string instance    = "commonapi.CarInfo";
    std::string connection  = "service-CarInfo";
    // create service
    std::shared_ptr<CarInfoStubImpl> myService = std::make_shared<CarInfoStubImpl>();
    // register service
    bool successfullyRegistered = runtime->registerService(domain, instance, myService, connection);
    // if registration failed, try again
    while (!successfullyRegistered) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        successfullyRegistered = runtime->registerService(domain, instance, myService, connection);
    }
    std::cout << "Successfully Registered Service!" << std::endl;
	
    /*main loop */
    while (true)
	{
		// locks python interpreter
		PyGILState_STATE gilState = PyGILState_Ensure();
		// read battery info
        piracer->readBatteryInfo();
        float voltage       = piracer->getBatteryVoltage();
        float current       = piracer->getBatteryCurrent();
        float consumption   = piracer->getBatteryConsumption();
        float level         = piracer->getBatteryLevel();
        // set to myService
        myService->setBatteryStruct(level, voltage, current, consumption);
		// release python interpreter
		PyGILState_Release(gilState);
        // sleep for 1 second
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
    return 0;
}