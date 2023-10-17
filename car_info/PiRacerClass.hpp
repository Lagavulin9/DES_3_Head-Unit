#ifndef PIRACERCLASS_HPP
#define PIRACERCLASS_HPP

#include <stdint.h>
#include <Python.h>
#include <iostream>
#include <mutex>
#include <thread>

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
        static PiRacerClass *pInstance_;
        static std::mutex mutex_;
    protected:
        PiRacerClass();
        ~PiRacerClass();
    public:
        PiRacerClass(PiRacerClass &other) = delete;
        void operator=(const PiRacerClass &) = delete;
        static PiRacerClass *getInstance();
        void pyconnector_update_battery_info();
        const double &pyconnector_get_voltage();
        const double &pyconnector_get_current();
        const double &pyconnector_get_power_consumption();
        const int    &pyconnector_get_battery_level();
};
#endif







