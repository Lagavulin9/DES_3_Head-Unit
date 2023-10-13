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
        PyObject *pgear;
        PyObject *pindicator;
    public:
        // Default constructor
        PiRacerClass();
        // Connecotor methods to Python
        void pyconnector_read_gamepad();
        void pyconnector_set_gear(char gear);
        const char* pyconnector_get_gear();
        const char* pyconnector_get_indicator();
        // Destructor
        ~PiRacerClass();
};

//extern PiRacerClass piracer;

#endif