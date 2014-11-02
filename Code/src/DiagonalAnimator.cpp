#include "DiagonalAnimator.h"


void DiagonalAnimator::nextGeneration() {
	getField()->fillFieldMono(false);
    unsigned int x = m_numberOfPassedCycles % 8;
    unsigned int y = m_numberOfPassedCycles % 8;
    getField()->setCell(7 - x, y, true);
    getField()->setCell(x, 7 - y, true);
    getField()->setCell(7- x, 7 - y, true);
    getField()->setCell(x, y, true);
    ++m_numberOfPassedCycles;
}

void DiagonalAnimator::mainloop() {
	nextGeneration();
	showCycles(16);
}
