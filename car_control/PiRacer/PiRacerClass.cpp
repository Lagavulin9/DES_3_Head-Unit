// Include header
#include "PiRacerClass.hpp"

// Constructor
PiracerClass::PiRacerClass()
{
    Py_Initialize();
    pModule = PyImport_ImportModule("piracer.vehicles");
    pClass = PyObject_GetAttrString(pModule, "PiRacer");
    pInstance = PyObject_CallObject(pClass, NULL);
    gearMode = 0;
}

// setter
void PiracerClass::setGear(uint16_t _gearMode)
{
    gearMode = _gearMode;
    return;
}

// void PiracerClass::applyThrottle(double throttle)
// {
//     pArgs = PyTuple_Pack(1, PyFloat_FromDouble(throttle));
//     PyObject_CallMethod(pInstance, "set_throttle_percent", "O", pArgs);
//     return;
// }

// void PiracerClass::applySteering(double steering)
// {
//     pArgs = PyTuple_Pack(1, PyFloat_FromDouble(steering * -1.0));
//     PyObject_CallMethod(pInstance, "set_steering_percent", "O", pArgs);
//     return;
// }

// getter
uint16_t PiracerClass::getGearMode()
{
    return gearMode;
}

// Destructor
PiracerClass::~PiracerClass()
{
    Py_DECREF(pArgs);
    Py_DECREF(pInstance);
    Py_DECREF(pClass);
    Py_DECREF(pModule);
    Py_Finalize();
}

PiracerClass piracer;