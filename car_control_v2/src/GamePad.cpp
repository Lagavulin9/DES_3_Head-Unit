#include "GamePad.hpp"

GamePad::GamePad()
{
	_input.analog_stick_left = {0,0,0};
	_input.analog_stick_right = {0,0,0};
	_input.button_x = false;
	_input.button_y = false;
	_input.button_a = false;
	_input.button_b = false;
	_input.button_select = false;
	_input.button_start = false;
	_input.button_home = false;
	_input.button_l1 = 0;
	_input.button_l2 = 0;
	_input.button_r1 = 0;
	_input.button_r2 = 0;
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
	return Input();
}