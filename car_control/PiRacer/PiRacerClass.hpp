#ifndef PIRACERCLASS_HPP
#define PIRACERCLASS_HPP

#include <stdint.h>
#include <Python.h>

class PiRacerClass
{
    private:
        PyObject *pModule, *pClass, *pInstance, *pArgs;
        // shared_ptr<char> gear_; 
        // shared_ptr<char> indicator_;
        //char indicator;
        //char gear;
    public:
        // Default constructor
        PiRacerClass();
        //setter
        void set_gear(char g);
        //getter
        char get_gear() const;
        char get_indicator() const;
        // Destructor
        ~PiRacerClass();
};

extern PiRacerClass piracer;

#endif