#pragma once
#ifndef __PIRACER_HPP__
# define __PIRACER_HPP__

#include <iostream>
#include <string>
#include <mutex>

class PiRacer
{
private:
	std::string	_gear;
	std::string	_indicator;
	double		_throttle;
	double		_steering;
	std::mutex	_mutex;

	PiRacer();
	~PiRacer();
	PiRacer(const PiRacer&) = delete;
	PiRacer& operator=(const PiRacer&) = delete;
public:
	static PiRacer*		getInstance();
	const std::string&	getGear();
	const std::string&	getIndicator();
	bool				setGear(const std::string&);
	bool				setIndicator(const std::string&);
	bool				setThrottle(const double&);
	bool				setSteering(const double&);
};

#endif