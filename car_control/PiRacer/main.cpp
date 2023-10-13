#include <iostream>
#include <string>
#include <unistd.h>
#include "PiRacerClass.hpp"

int main ()
{   
    PiRacerClass piracer;
    while (1)
    {
        std::cout << "blinker: " << piracer.pyconnector_get_indicator() << std::endl;
        std::cout << "gear: " <<  piracer.pyconnector_get_gear() << std::endl;
    }

    return 0;
}