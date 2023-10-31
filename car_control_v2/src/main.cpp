#include "GamePad.hpp"
#include "PiRacer.hpp"
#include <thread>
#include <chrono>
#include <csignal>
#include <cstdlib>
#include <unistd.h>
#include <Python.h>

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

int main(void)
{
	signal(SIGINT, signalHandler);
	signal(SIGQUIT, signalHandler);

	setenv("PYTHONPATH", "../piracer", 0);
	Py_Initialize();
	atexit(cleanUp);

	GamePad* gamepad = GamePad::getInstance();
	PiRacer* piracer = PiRacer::getInstance();

	while (true)
	{
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
	}
	return (0);
}