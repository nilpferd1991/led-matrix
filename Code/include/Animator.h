#pragma once

#include <Field.h>
#include <InterfaceLED.h>

class Animator {
    public:
        Animator();
        void nextGeneration();
        void setFieldMono(bool status);
        void showCycles(const uint16_t numberOfCycles);
    private:
        unsigned int m_numberOfGenerations;
        Field * m_field;
        LEDMatrixHardware m_interfaceToHardware;
};
