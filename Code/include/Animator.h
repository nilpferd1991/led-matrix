#pragma once

#include <Field.h>
#include <InterfaceLED.h>

class Animator {
    public:
        Animator();
        void nextGeneration();
        void heartShape();
        void setFieldMono(bool status);
        void showCycles(const uint16_t numberOfCycles);

        void mainloop();

        Field * const getField() const { return m_field; }

    private:
        uint16_t m_numberOfGenerations;
        Field * m_field;
        LEDMatrixHardware m_interfaceToHardware;
};
