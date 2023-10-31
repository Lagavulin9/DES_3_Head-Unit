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
		piracer->setGear("N");
		piracer->setIndicator("Right");
		piracer->setThrottle(0.1);
		piracer->setSteering(11);
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	return (0);
}