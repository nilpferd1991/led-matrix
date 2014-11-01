#pragma once

#include <Animator.h>
#include <Point.h>
#include <stdlib.h>

class SnakeAnimator : public Animator {
public:
	SnakeAnimator() : m_snakeLength(1), m_numberOfCompletedCycles(0),
	m_currentSnakePosition(0, 0), m_foodPosition(0, 0) { Animator(); }

    void mainloop();

private:
    void displayOnlySingleDotOfSnake(uint16_t numberOfGenerations);
    void displaySnakeAndFood();
    void setFoodRandomly();
    void displayFood();
	void resetSnakeLength();
	void snakeHasFoundFood();
	void displayFullSnake();

    uint8_t m_snakeLength;
    uint8_t m_numberOfCompletedCycles;
    Point m_currentSnakePosition;
    Point m_foodPosition;
};
