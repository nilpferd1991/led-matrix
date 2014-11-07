#include "../include/HeartAnimator.h"

void HeartAnimator::heartShape() {
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
