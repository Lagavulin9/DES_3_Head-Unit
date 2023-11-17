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
		std::cout << "Failed to create PiRacer instance." << std::endl;
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
	// read absolut voltage from piracer
	py::object get_battery_voltage = pInstance.attr("get_battery_voltage");
	_voltage = std::abs(py::extract<float>(get_battery_voltage()));
	// read absolut current from piracer
	py::object get_battery_consumption = pInstance.attr("get_power_consumption");
	_consumption = std::abs(py::extract<float>(get_battery_consumption()));
	// read absolut current from piracer
	py::object get_battery_current = pInstance.attr("get_battery_current");
	_current = std::abs(py::extract<float>(get_battery_current()));
	// calculate battery level
	// This is a 3rd degree polynomial fit of the data from the battery discharge curve (see car_info.md for more details)
	// limit to 0.01 - 100.00 & convert to 0.00 - 1.00
	double x = _voltage / _numcells;
	double y = -691.919 * pow(x,3) + 7991.667 * pow(x,2) - 30541.295 * x + 38661.5;
	y = std::min(std::max(y, 0.01), 100.00); 
	_level = y / 100.00; 
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