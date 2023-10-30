#pragma once
#ifndef __GAMEPAD_HPP__
# define __GAMEPAD_HPP__

#include <iostream>
#include <mutex>

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
	Input	_input;

	GamePad();
	~GamePad();
	GamePad(const GamePad&) = delete;
	GamePad& operator=(const GamePad&) = delete;
public:
	static GamePad*	getInstance();
	void 			readInput();
	void			updateInput();
};

#endif