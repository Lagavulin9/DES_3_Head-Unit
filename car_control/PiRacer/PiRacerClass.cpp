#include 
#include "PiRacerClass.hpp"

PiracerClass::PiRacerClass()
{
    Py_Initialize();
    pModule = PyImport_ImportModule("PiRacer");
    pClass = PyObject_GetAttrString(pModule, "PiRacer");
    pInstance = PyObject_CallObject(pClass, NULL);
    //shared_ptr<char> gear_ = make_shared<char>('N');
    //shared_ptr<char> indicator_ = make_shared<char>('');
    //char gear_ = 'N';
    //char indicator_ = '';
}

void PiracerClass::set_gear(char gear)
{
    //*gear_ = gear;
    PyObject_CallMethod(pInstance, "set_gear", "c", gear);
}

char PiracerClass::get_indicator()
{
    //*indicator_ = PyObject_CallMethod(pInstance, "get_indicator", NULL);
    //return *indicator_;
    return PyObject_CallMethod(pInstance, "get_indicator", NULL);
}

char PiracerClass::get_gear()
{   
    return PyObject_CallMethod(pInstance, "get_gear", NULL);
}

PiracerClass::~PiracerClass()
{
    Py_DECREF(pArgs);
    Py_DECREF(pModule);
    Py_DECREF(pInstance);
    Py_DECREF(pClass);
    Py_Finalize();
}