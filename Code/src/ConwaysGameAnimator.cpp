#include <ConwaysGameAnimator.h>



void ConwaysGameAnimator::checkEveryNeighbour(uint8_t cellPositionRow, uint8_t cellPositionColumn) {

}

void ConwaysGameAnimator::initCells() {
	getField()->setCell(0, 6, true);
	getField()->setCell(5, 1, true);
	getField()->setCell(0, 5, true);
	getField()->setCell(4, 6, true);
	getField()->setCell(3, 6, true);
	getField()->setCell(2, 6, true);
}

void ConwaysGameAnimator::displayConwaysGame() {
	getField()->fillFieldMono(false);

	initCells();


}

void ConwaysGameAnimator::mainloop() {
	displayConwaysGame();
	showCycles(16);
}
