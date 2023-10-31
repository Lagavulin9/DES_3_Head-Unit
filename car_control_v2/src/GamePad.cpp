#include "GamePad.hpp"

GamePad::GamePad()
{
	bzero(&_input, sizeof(Input));
	try 
	{
		pModule = py::import(GAMEPAD_MODULE_NAME);
		pClass = pModule.attr(GAMEPAD_CLASS_NAME);
		pInstance = pClass();
	}
	catch (const py::error_already_set&)
	{
		PyErr_Print();
		exit(1);
	}
	std::cout << "GamePad instance created" << std::endl;
}

GamePad::~GamePad()
{
	std::cout << "removing gamepad instance" << std::endl;
}

GamePad* GamePad::getInstance()
{
	static GamePad _instance;
	return &_instance;
}

Input GamePad::readInput()
{
	//TODO: read from python and update
	std::cout << "reading input" << std::endl;
	try
	{
		py::object read_data = pInstance.attr("read_data");
		py::object input = read_data();
		convert(input);
	}
	catch (const py::error_already_set&)
	{
		PyErr_Print();
		exit(1);
	}
	return Input();
}

Input GamePad::convert(const py::object& py_input)
{
	Input _input;

	py::object py_analog_left = py_input.attr("analog_stick_left");
	_input.analog_stick_left.x = py::extract<double>(py_analog_left.attr("x"));
	_input.analog_stick_left.y = py::extract<double>(py_analog_left.attr("y"));
	_input.analog_stick_left.z = py::extract<double>(py_analog_left.attr("z"));

	py::object py_analog_right = py_input.attr("analog_stick_right");
	_input.analog_stick_right.x = py::extract<double>(py_analog_right.attr("x"));
	_input.analog_stick_right.y = py::extract<double>(py_analog_right.attr("y"));
	_input.analog_stick_right.z = py::extract<double>(py_analog_right.attr("z"));

	// I don't like the code but... attributes were optional so I had to
	_input.button_x = hasAttr(py_input, "button_x") \
					? py::extract<bool>(py_input.attr("button_x")) : false;
	_input.button_y = hasAttr(py_input, "button_y") \
					? py::extract<bool>(py_input.attr("button_y")) : false;
	_input.button_a = hasAttr(py_input, "button_a") \
					? py::extract<bool>(py_input.attr("button_a")) : false;
	_input.button_b = hasAttr(py_input, "button_b") \
					? py::extract<bool>(py_input.attr("button_b")) : false;
	_input.button_select = hasAttr(py_input, "button_select") \
					? py::extract<bool>(py_input.attr("button_select")) : false;
	_input.button_start = hasAttr(py_input, "button_start") \
					? py::extract<bool>(py_input.attr("button_start")) : false;
	_input.button_home = hasAttr(py_input, "button_home") \
					? py::extract<bool>(py_input.attr("button_home")) : false;

	// I don't know why but these buttons are float in piracer library
	_input.button_l1 = hasAttr(py_input, "button_l1") \
					? py::extract<double>(py_input.attr("button_l1")) : 0.0;
	_input.button_l2 = hasAttr(py_input, "button_l2") \
					? py::extract<double>(py_input.attr("button_l2")) : 0.0;
	_input.button_r1 = hasAttr(py_input, "button_r1") \
					? py::extract<double>(py_input.attr("button_r1")) : 0.0;
	_input.button_r2 = hasAttr(py_input, "button_r2") \
					? py::extract<double>(py_input.attr("button_r2")) : 0.0;

	return _input;
}

bool GamePad::hasAttr(const py::object& obj, const char* attr_name)
{
	return PyObject_HasAttrString(obj.ptr(), attr_name);
}