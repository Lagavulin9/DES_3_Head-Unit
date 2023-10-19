#include <iostream>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include "PiRacerInfoClass.hpp"

int main ()
{   
    PiRacerInfoClass* piracer = PiRacerInfoClass::getInstance();
    while (1){
        piracer->pyconnector_update_battery_info();
        std::cout << "Voltage: " << piracer->pyconnector_get_voltage() << std::endl;
        std::cout << "Current: " << piracer->pyconnector_get_current() << std::endl;
        std::cout << "Power Consumption: " << piracer->pyconnector_get_power_consumption() << std::endl;
        std::cout << "Battery Level: " << piracer->pyconnector_get_battery_level() << std::endl;
        sleep(1);
    }
    return 0;
}