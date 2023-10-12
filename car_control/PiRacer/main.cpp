#include <iostream>
#include <string>
#include <unistd.h>
#include "PiRacerClass.hpp"

int main ()
{   
    PiRacerClass piracer;
    while (1)
    {
        char blinker = piracer.getIndicator();
        char gear = piracer.getGear();
        std::cout << "blinker: " << blinker << std::endl;
        std::cout << "gear: " << gear << std::endl;
    }
    return 0;
}