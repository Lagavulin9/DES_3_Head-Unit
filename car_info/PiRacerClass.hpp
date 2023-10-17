#ifndef PIRACERCLASS_HPP
#define PIRACERCLASS_HPP

#include <stdint.h>
#include <Python.h>

class PiRacerClass
{
    private:
        PyObject *pModule;
        PyObject *pClass;
        PyObject *pInstance;
        PyObject *pArgs;
        PyObject *pVoltage;
        PyObject *pCurrent;
        PyObject *pPowerConsumption;
        PyObject *pBatteryLevel;
    public:
        // Default constructor
        PiRacerClass();
        // Connecotor methods to Python
        void pyconnector_update_battery_info();
        const double &pyconnector_get_voltage();
        const double &pyconnector_get_current();
        const double &pyconnector_get_power_consumption();
        const int    &pyconnector_get_battery_level();
        // Destructors
        ~PiRacerClass();
};
#endif