#include <Evolution.h>
#include <Field.h>


Evolution::Evolution() : m_numberOfGenerations(0) {
}

Field* const Evolution::animation(Field* const currentGeneration) {
    Field nextGeneration;
    unsigned int x = m_numberOfGenerations % 8;
    unsigned int y = m_numberOfGenerations % 8;
    nextGeneration.setField(8 - x, y, true);
    nextGeneration.setField(x, 8 - y, true);
    ++m_numberOfGenerations;
    return &nextGeneration;
}


Field* const Evolution::conway(Field* const currentGeneration) { 
    Field nextGeneration;

    ++m_numberOfGenerations;
    return &nextGeneration;
}
