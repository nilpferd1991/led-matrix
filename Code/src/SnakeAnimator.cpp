#include <SnakeAnimator.h>

void SnakeAnimator::displayOnlySingleDotOfSnake(uint16_t numberOfGenerations) {
	uint8_t row = (numberOfGenerations / 8) % 8;
	uint8_t column = numberOfGenerations % 8;

	if (row % 2 == 0) {
		m_currentSnakePosition = Point(row, column);
	}
	else {
		m_currentSnakePosition = Point(row, 7 - column);
	}

	getField()->setCell(m_currentSnakePosition.m_row, m_currentSnakePosition.m_column, true);
}

void SnakeAnimator::resetSnakeLength() {
	setFieldMono(true);
	showCycles(16);
	setFieldMono(false);
	m_snakeLength = 1;
}

void SnakeAnimator::snakeHasFoundFood() {
	setFoodRandomly();
	m_snakeLength++;
	if (m_snakeLength > 16) {
		resetSnakeLength();
	}
}

void SnakeAnimator::displayFullSnake() {
	for (uint8_t snakeDots = 0; snakeDots < m_snakeLength; snakeDots++) {
		displayOnlySingleDotOfSnake(
				m_numberOfCompletedCycles - m_snakeLength + snakeDots - 1);
	}
}

void SnakeAnimator::lookForFood() {
	if (m_foodPosition == m_currentSnakePosition) {
		snakeHasFoundFood();
	}
}

void SnakeAnimator::displaySnakeAndFood() {
	getField()->fillFieldMono(false);

	displayFullSnake();
	displayFood();
	lookForFood();

    ++m_numberOfCompletedCycles;
}

void SnakeAnimator::displayFood() {
	getField()->setCell(m_foodPosition.m_row, m_foodPosition.m_column, true);
}

void SnakeAnimator::setFoodRandomly() {
	uint8_t randomFoodPosition = rand() % 64;
	uint8_t row = randomFoodPosition / 8;
	uint8_t column = randomFoodPosition % 8;

	m_foodPosition = Point(row, column);
}

void SnakeAnimator::mainloop() {
	displaySnakeAndFood();
	showCycles(16);
}
