#include "PiRacer.hpp"

PiRacer::PiRacer():
	_gear("P"),
	_indicator("None"),
	_throttle(0),
	_steering(0)
{
	std::cout << "instance Created" << std::endl;
}

PiRacer::~PiRacer()
{
	std::cout << "removing PiRacer instance" << std::endl;
}

PiRacer* PiRacer::getInstance()
{
	static PiRacer _instance;
	return &_instance;
}

const std::string& PiRacer::getGear()
{
	return _gear;
}

const std::string& PiRacer::getIndicator()
{
	return _indicator;
}

bool PiRacer::setGear(const std::string& gear)
{
	std::lock_guard<std::mutex>	lock(_mutex);
	if (_throttle >= 1)
		return false;
	_gear = gear;
	std::cout << "gear set to: " << gear << std::endl;
	return true;
}

bool PiRacer::setIndicator(const std::string& indicator)
{
	_indicator = indicator;
	std::cout << "indicator set to: " << indicator << std::endl;
	return true;
}

bool PiRacer::setThrottle(const double& throttle)
{
	_throttle = throttle;
	std::cout << "throttle set to: " << throttle << std::endl;
	return true;
}

bool PiRacer::setSteering(const double& steering)
{
	_steering = steering;
	std::cout << "steering set to: " << steering << std::endl;
	return true;
}