#ifndef PIRACERINFOCLASS_HPP
#define PIRACERINFOCLASS_HPP

#include <stdint.h>
#include <Python.h>
#include <iostream>
#include <mutex>
#include <thread>

class PiRacerInfoClass
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
        static PiRacerInfoClass *pInstance_;
        static std::mutex mutex_;
    protected:
        PiRacerInfoClass();
        ~PiRacerInfoClass();
    public:
        PiRacerInfoClass(PiRacerInfoClass &other) = delete;
        void operator=(const PiRacerInfoClass &) = delete;
        static PiRacerInfoClass *getInstance();
        void pyconnector_update_battery_info();
        const double &pyconnector_get_voltage();
        const double &pyconnector_get_current();
        const double &pyconnector_get_power_consumption();
        const int    &pyconnector_get_battery_level();
};
#endif







