#include <Evolution.h>
#include <Field.h>


Evolution::Evolution() : m_numberOfGenerations(0) {
}

Field* const Evolution::animation(Field* const currentGeneration) {
    currentGeneration->fillFieldMono(false);
    unsigned int x = m_numberOfGenerations % 8;
    unsigned int y = m_numberOfGenerations % 8;
    currentGeneration->setField(7 - x, y, true);
    currentGeneration->setField(x, 7 - y, true);
    ++m_numberOfGenerations;
    return currentGeneration;
}


Field* const Evolution::conway(Field* const currentGeneration) { 
    Field nextGeneration;

    ++m_numberOfGenerations;
    return &nextGeneration;
}
