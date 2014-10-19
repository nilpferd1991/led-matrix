#pragma once

#include <Field.h>

class Animator {
    public:
        Animator(Field * const field);
        const Field* const getNextGeneration();
        Field* const getField() { return m_field; }
        void setField(Field * const field) { m_field = field; }
    private:
        unsigned int m_numberOfGenerations;
        Field * m_field;
};
