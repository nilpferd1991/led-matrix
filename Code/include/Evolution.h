#pragma once

#include <Field.h>

class Evolution {
    public:
        Evolution();
        Field* const animation(Field* const currentGeneration);
        Field* const conway(Field* const currentGeneration);
    private:
        unsigned int m_numberOfGenerations;
        Field * m_field;
};
