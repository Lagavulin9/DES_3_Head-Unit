#include <iostream>
#include "PiRacerClass.hpp"

int main ()
{   
    PiRacerClass piracer;
    while (1){
        piracer.pyconnector_read_gamepad(); // continoisly fetching gamepad inputs
        std::cout << piracer.pyconnector_get_indicator() << std::endl;
        std::cout << piracer.pyconnector_get_gear() << std::endl;
    }
    return 0;
}