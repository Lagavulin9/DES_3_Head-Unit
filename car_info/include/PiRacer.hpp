#pragma once
#ifndef __PIRACER_HPP__
# define __PIRACER_HPP__

#include <iostream>
#include <string>
#include <mutex>
#include <boost/python.hpp>
#include <cmath>
#include <algorithm>

#define PIRACER_MODULE_NAME "vehicles"
#define PIRACER_CLASS_NAME "PiRacerStandard"

namespace py = boost::python;

class PiRacer
{
private:
	float				_level;
	float				_voltage;
    float				_current;
    float				_consumption;
	int					_numcells;
	py::object			pModule;
	py::object			pClass;
	py::object			pInstance;
	static PiRacer* 	_instance;
	static std::mutex	_mutex;
protected:
	PiRacer();
	~PiRacer();
public:
	PiRacer(PiRacer&) = delete;
	PiRacer& operator=(const PiRacer&) = delete;
	static PiRacer*		getInstance();
	bool 				deleteInstance();
    void                readBatteryInfo();
    const float	        getBatteryLevel();
	const float	        getBatteryVoltage();
	const float	        getBatteryCurrent();
	const float	        getBatteryConsumption();
};

#endif