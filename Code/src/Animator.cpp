#include "../include/Animator.h"

#include <Field.h>


Animator::Animator(Field * const field) :
		m_numberOfGenerations (0), m_field(field) {
}

const Field* const  Animator::getNextGeneration() {
	m_field->fillFieldMono(false);
    unsigned int x = m_numberOfGenerations % 8;
    unsigned int y = m_numberOfGenerations % 8;
    m_field->setField(7 - x, y, true);
    m_field->setField(x, 7 - y, true);
    m_field->setField(7- x, 7 - y, true);
    m_field->setField(x, y, true);
    ++m_numberOfGenerations;
    return m_field;
}
