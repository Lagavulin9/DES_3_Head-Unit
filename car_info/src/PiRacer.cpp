#include "PiRacer.hpp"

//Initialize static memeber variables
PiRacer* PiRacer::_instance{nullptr};
std::mutex PiRacer::_mutex;

PiRacer::PiRacer():
	_level(0.0),
	_voltage(0.0),
	_current(0.0),
	_consumption(0.0),
	_numcells(3)
{
	try
	{
		pModule = py::import(PIRACER_MODULE_NAME);
		pClass = pModule.attr(PIRACER_CLASS_NAME);
		pInstance = pClass();
	}
	catch(const py::error_already_set&)
	{
		PyErr_Print();
		exit(1);
	}
	std::cout << "PiRacer instance created." << std::endl;
}

PiRacer::~PiRacer()
{
	std::cout << "PiRacer DestRemoving PiRacer instance." << std::endl;
}

PiRacer* PiRacer::getInstance()
{
	std::lock_guard<std::mutex> lock(_mutex);
	if(_instance == nullptr)
	{
		std::cout << "Creating PiRacer instance." << std::endl;
		_instance = new PiRacer();
	}
	return _instance;
}

bool PiRacer::deleteInstance()
{	
	std::cout << "PiRacer's deleteInstance() called" << std::endl;
	std::lock_guard<std::mutex> lock(_mutex);
	if(_instance != nullptr)
	{
		std::cout << _instance << std::endl;
		std::cout << "Deleting PiRacer instance." << std::endl;
		delete _instance;
		_instance = nullptr;
		return true;
	}
    return false;
}

void PiRacer::readBatteryInfo(){
	py::object get_battery_voltage 		= pInstance.attr("get_battery_voltage");
	_voltage = py::extract<float>(get_battery_voltage());
	py::object get_battery_consumption 	= pInstance.attr("get_battery_consumption");
	_consumption = py::extract<float>(get_battery_consumption());
	py::object get_battery_current 		= pInstance.attr("get_battery_current");
	_current = py::extract<float>(get_battery_current());
	double x = _voltage / _numcells;
	double y = -691.919 * pow(x,3) + 7991.667 * pow(x,2) - 30541.295 * x + 38661.5;
    // nomalized value
    _level = y ;//min(max(round(y, 3), 0), 100);
}

const float PiRacer::getBatteryLevel()
{
	return _level;
}

const float PiRacer::getBatteryVoltage()
{
	return _voltage;
}

const float PiRacer::getBatteryCurrent()
{
	return _current;
}

const float PiRacer::getBatteryConsumption()
{
	return _consumption;
}