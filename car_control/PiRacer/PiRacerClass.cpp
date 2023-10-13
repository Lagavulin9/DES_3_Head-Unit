#include "PiRacerClass.hpp"
#include <iostream>

// Default constructor
PiRacerClass::PiRacerClass()
{
    Py_Initialize();                                 // Initialize Python interpreter
    pModule = PyImport_ImportModule("car");          // Import Python module
    pClass = PyObject_GetAttrString(pModule, "Car"); // Get Python class
    pInstance = PyObject_CallObject(pClass, NULL);   // Create Python instance
}
void PiRacerClass::pyconnector_read_gamepad()
{
    PyObject_CallMethod(pInstance, "read_gamepad", NULL);
}
// Connecotor methods to Python
void PiRacerClass::pyconnector_set_gear(char gear)
{
    PyObject_CallMethod(pInstance, "set_gear", "c", gear);
}
const char* PiRacerClass::pyconnector_get_gear()
{   
    pgear = PyObject_CallMethod(pInstance, "get_gear", NULL);
    return PyUnicode_AsUTF8(pgear);
}
const char* PiRacerClass::pyconnector_get_indicator()
{
    pindicator = PyObject_CallMethod(pInstance, "get_indicator", NULL);
    return PyUnicode_AsUTF8(pindicator);
}
// Destructor
PiRacerClass::~PiRacerClass()
{
    Py_DECREF(pArgs);
    Py_DECREF(pgear);
    Py_DECREF(pindicator);
    Py_DECREF(pModule);
    Py_DECREF(pInstance);
    Py_DECREF(pClass);
    Py_Finalize();
}

//PiRacerClass piracer;
