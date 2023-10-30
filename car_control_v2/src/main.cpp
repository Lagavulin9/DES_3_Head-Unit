#include "GamePad.hpp"
#include "PiRacer.hpp"
#include <thread>
#include <chrono>
#include <atomic>
#include <csignal>
#include <unistd.h>

std::atomic<bool> running;

void signalHandler(int signum)
{
	std::cout << "signal: " << signum << std::endl;
	running.store(false);
	std::cout << "Shutting down..." << std::endl;
}

int main(void)
{
	signal(SIGINT, signalHandler);

	GamePad* gamepad = GamePad::getInstance();
	PiRacer* piracer = PiRacer::getInstance();

	running.store(true);

	while (running)
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