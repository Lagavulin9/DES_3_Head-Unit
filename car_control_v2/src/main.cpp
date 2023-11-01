#include "GamePad.hpp"
#include "PiRacer.hpp"
#include <thread>
#include <chrono>
#include <csignal>
#include <cstdlib>
#include <unistd.h>
#include <vector>
#include <Python.h>

std::mutex _mutex;

void signalHandler(int signum)
{
	std::cout << "\nsignal: " << signum << std::endl;
	std::cout << "Shutting down..." << std::endl;
	exit(128 + signum);
}

void cleanUp()
{
	Py_Finalize();
	std::cout << "Python Interpreter Finalized" << std::endl;
}

void notify()
{
	PiRacer* piracer = PiRacer::getInstance();
	std::vector<std::string> gears = {"P", "R", "N", "D"};

	while (true)
	{
		{
			PyGILState_STATE gilState = PyGILState_Ensure(); 
			std::string random_gear = gears[std::rand() % 4];
			std::cout << "HU - Event: " << random_gear << std::endl;
			piracer->setGear(random_gear);
			PyGILState_Release(gilState);
		}
		std::this_thread::sleep_for(std::chrono::seconds(5));
	}
}

int main(void)
{
	signal(SIGINT, signalHandler);
	signal(SIGQUIT, signalHandler);

	setenv("PYTHONPATH", "../piracer", 0);
	Py_Initialize();
	atexit(cleanUp);

	GamePad* gamepad = GamePad::getInstance();
	PiRacer* piracer = PiRacer::getInstance();

	std::thread dummy(notify);
	dummy.detach();

	while (true)
	{
		PyGILState_STATE gilState = PyGILState_Ensure();
		Input input = gamepad->readInput();
		if (input.button_x)
			piracer->setGear("N");
		else if (input.button_y)
			piracer->setGear("R");
		else if (input.button_a)
			piracer->setGear("D");
		else if (input.button_b)
			piracer->setGear("P");
		if (input.button_l1)
			piracer->setIndicator("Left");
		else if (input.button_r1)
			piracer->setIndicator("Right");
		else
			piracer->setIndicator("None");
		piracer->setThrottle(input.analog_stick_right.y * 0.5);
		piracer->setSteering(input.analog_stick_left.x);
		PyGILState_Release(gilState);
	}
	return (0);
}