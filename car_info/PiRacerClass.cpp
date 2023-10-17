#include "PiRacerClass.hpp"

PiRacerClass::PiRacerClass()
{
    Py_Initialize();                                 
    pModule = PyImport_ImportModule("car");          
    pClass = PyObject_GetAttrString(pModule, "Car"); 
    pInstance = PyObject_CallObject(pClass, NULL);  
}

void PiRacerClass::pyconnector_update_battery_info()
{
    PyObject_CallMethod(pInstance, "update_battery_info", NULL);
}

const double *PiRacerClass::pyconnector_get_voltage()
{
    pVoltage = PyObject_CallMethod(pInstance, "get_voltage", NULL);
    return PyFloat_AsDouble(pVoltage);
}

const double *PiRacerClass::pyconnector_get_current()
{
    pCurrent = PyObject_CallMethod(pInstance, "get_current", NULL);
    return PyFloat_AsDouble(pCurrent);
}

const double *PiRacerClass::pyconnector_get_power_consumption()
{
    pPowerConsumption = PyObject_CallMethod(pInstance, "get_power_consumtion", NULL);
    return PyFloat_AsDouble(pPowerConsumption);
}

const int *PiRacerClass::pyconnector_get_battery_level()
{
    pBatteryLevel = PyObject_CallMethod(pInstance, "get_battery_level", NULL);
    return PyLong_AsInt(pBatteryLevel);
}

PiRacerClass::~PiRacerClass()
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
