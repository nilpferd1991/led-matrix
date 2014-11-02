#pragma once

#include <Field.h>
#include <InterfaceLED.h>

class Animator {
    public:
        Animator() : m_field(new Field), m_interfaceToHardware(LEDMatrixHardware()) { }
        void mainloop();
        void flashInTheBeginning();

        void heartShape();

        void setFieldMono(bool status) {
        	m_field->fillFieldMono(status);
        }

        void showCycles(const uint16_t numberOfCycles) {
        	m_interfaceToHardware.showCycles(m_field, numberOfCycles);
        }

        Field * const getField() const {
        	return m_field;
        }

    private:
        Field * m_field;
        LEDMatrixHardware m_interfaceToHardware;
};
