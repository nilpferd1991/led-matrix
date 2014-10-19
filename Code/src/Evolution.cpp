#include <Evolution.h>
#include <Field.h>


Evolution::Evolution() : m_numberOfGenerations(0) {
}

Field Evolution::evolve(const Field& currentGeneration) {
    Field nextGeneration;
    nextGeneration.setField(m_numberOfGenerations % 8, m_numberOfGenerations % 8, true);
    //Implement rules
    ++m_numberOfGenerations;
    return nextGeneration;
}
