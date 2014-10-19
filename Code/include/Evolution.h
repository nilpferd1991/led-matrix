#pragma once

#include <Field.h>

class Evolution {
    public:
        Evolution();
        Field evolve(const Field& currentGeneration);
    private:
        unsigned int m_numberOfGenerations;
};
