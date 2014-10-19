#include <Evolution.h>
#include <Field.h>


Evolution::Evolution() : m_numberOfGenerations(0) {
}

void Evolution::animation() {
	Field * newGeneration = new Field;
	newGeneration->fillFieldMono(false);
    unsigned int x = m_numberOfGenerations % 8;
    unsigned int y = m_numberOfGenerations % 8;
    newGeneration->setField(7 - x, y, true);
    newGeneration->setField(x, 7 - y, true);
    newGeneration->setField(7- x, 7 - y, true);
    newGeneration->setField(x, y, true);
    ++m_numberOfGenerations;
    m_field = newGeneration;
}


Field* const Evolution::conway(Field* const currentGeneration) { 
    Field nextGeneration;

    ++m_numberOfGenerations;
    return &nextGeneration;
}
