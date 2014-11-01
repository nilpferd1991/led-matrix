#include "../include/Animator.h"

Animator::Animator() :
		m_numberOfGenerations (0), m_field(new Field),
		m_interfaceToHardware(LEDMatrixHardware()) {
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

void Animator::heartShape() {
	m_field->fillFieldMono(true);

	m_field->setCell(0, 0, false);
	m_field->setCell(0, 5, false);
	m_field->setCell(0, 6, false);
	m_field->setCell(0, 7, false);
	m_field->setCell(1, 6, false);
	m_field->setCell(1, 7, false);
	m_field->setCell(2, 7, false);
	m_field->setCell(3, 0, false);

	m_field->setCell(7, 0, false);
	m_field->setCell(7, 5, false);
	m_field->setCell(7, 6, false);
	m_field->setCell(7, 7, false);
	m_field->setCell(6, 6, false);
	m_field->setCell(6, 7, false);
	m_field->setCell(5, 7, false);
	m_field->setCell(4, 0, false);
}


void Animator::setFieldMono(bool status) {
	m_field->fillFieldMono(status);
}

void Animator::showCycles(uint16_t numberOfCycles) {
	m_interfaceToHardware.showCycles(m_field, numberOfCycles);
}
