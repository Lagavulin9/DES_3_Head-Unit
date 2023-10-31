#pragma once
#ifndef __GAMEPAD_HPP__
# define __GAMEPAD_HPP__

#include <iostream>
#include <mutex>
#include <boost/python.hpp>

#define GAMEPAD_MODULE_NAME "gamepads"
#define GAMEPAD_CLASS_NAME "ShanWanGamepad"

namespace py = boost::python;

typedef struct
{
	double x;
	double y;
	double z;
} Vector3d;

typedef struct
{
	Vector3d	analog_stick_left;
	Vector3d	analog_stick_right;
	bool		button_x;
	bool		button_y;
	bool		button_a;
	bool		button_b;
	bool		button_select;
	bool		button_start;
	bool		button_home;
	double		button_l1;
	double		button_l2;
	double		button_r1;
	double		button_r2;
} Input;

class GamePad
{
private:
	Input		_input;
	py::object	pModule;
	py::object	pClass;
	py::object	pInstance;

	GamePad();
	~GamePad();
	GamePad(const GamePad&) = delete;
	GamePad& operator=(const GamePad&) = delete;
	Input			convert(const py::object&);
	bool			hasAttr(const py::object&, const char*);
public:
	static GamePad*	getInstance();
	Input 			readInput();
};

#endif