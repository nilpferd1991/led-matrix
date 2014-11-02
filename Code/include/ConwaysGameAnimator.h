#pragma once

#include <Animator.h>
#include <stdlib.h>

class ConwaysGameAnimator : public Animator {
public:
	ConwaysGameAnimator() : m_cellStatus(false) { }
	void mainloop();

private:
	void checkEveryNeighbour(uint8_t cellPositionRow, uint8_t cellPositionColumn);
	void displayConwaysGame();
	void initCells();

	bool m_cellStatus;
};
