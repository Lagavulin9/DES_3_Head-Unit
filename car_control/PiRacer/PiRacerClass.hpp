#ifndef PIRACERCLASS_HPP
#define PIRACERCLASS_HPP

// Include necessary header
#include <stdint.h>
#include <Python.h>

class PiRacerClass
{
    private:
        PyObject *pModule, *pClass, *pInstance, *pArgs;
        char gear;
        char indicator;
        
    public:
        PiRacerClass();
        ~PiRacerClass();
        void setGear(char _gear);
        char getGear();
        char getIndicator();
};

extern PiRacerClass piracer;

#endif