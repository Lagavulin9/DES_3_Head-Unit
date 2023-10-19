#include "PiRacerInfoClass.hpp"

PiRacerInfoClass* PiRacerInfoClass::pInstance_{nullptr};
std::mutex PiRacerInfoClass::mutex_;

PiRacerInfoClass::PiRacerInfoClass()
{
    Py_Initialize();                                 
    pModule = PyImport_ImportModule("car");         
    std::cout << pModule << std::endl; 
    pClass = PyObject_GetAttrString(pModule, "Car"); 
    pInstance = PyObject_CallObject(pClass, NULL);  
}

PiRacerInfoClass *PiRacerInfoClass::getInstance()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pInstance_ == nullptr)
    {
        pInstance_ = new PiRacerInfoClass();
    }
    return pInstance_;
}

void PiRacerInfoClass::pyconnector_update_battery_info()
{
    PyObject_CallMethod(pInstance, "update_battery_info", NULL);
}

double PiRacerInfoClass::pyconnector_get_voltage()
{
    pVoltage = PyObject_CallMethod(pInstance, "get_voltage", NULL);
    std::cout << PyFloat_AsDouble(pVoltage) << std::endl;
    return PyFloat_AsDouble(pVoltage);
}

double PiRacerInfoClass::pyconnector_get_current()
{
    pCurrent = PyObject_CallMethod(pInstance, "get_current", NULL);
    return PyFloat_AsDouble(pCurrent);
}

double PiRacerInfoClass::pyconnector_get_power_consumption()
{
    pPowerConsumption = PyObject_CallMethod(pInstance, "get_power_consumtion", NULL);
    return PyFloat_AsDouble(pPowerConsumption);
}

int PiRacerInfoClass::pyconnector_get_battery_level()
{
    pBatteryLevel = PyObject_CallMethod(pInstance, "get_battery_level", NULL);
    return (int) PyLong_AsLong(pBatteryLevel);
}

PiRacerInfoClass::~PiRacerInfoClass()
{
    Py_DECREF(pModule);
    Py_DECREF(pArgs);
    Py_DECREF(pPowerConsumption);
    Py_DECREF(pCurrent);
    Py_DECREF(pVoltage);
    Py_DECREF(pBatteryLevel);
    Py_DECREF(pInstance);
    Py_DECREF(pClass);
    Py_Finalize();
}
