#include "../include/Animator.h"

Animator::Animator() :
		m_numberOfGenerations (0), m_field(new Field), m_interfaceToHardware(LEDMatrixHardware()) {
}

void Animator::nextGeneration() {
	m_field->fillFieldMono(false);
    unsigned int x = m_numberOfGenerations % 8;
    unsigned int y = m_numberOfGenerations % 8;
    m_field->setCell(7 - x, y, true);
    m_field->setCell(x, 7 - y, true);
    m_field->setCell(7- x, 7 - y, true);
    m_field->setCell(x, y, true);
    ++m_numberOfGenerations;
}

void Animator::setFieldMono(bool status) {
	m_field->fillFieldMono(status);
}

void Animator::showCycles(uint16_t numberOfCycles) {
	m_interfaceToHardware.showCycles(m_field, numberOfCycles);
}
