#pragma once

#include <Animator.h>

class DiagonalAnimator : public Animator {
public:
	DiagonalAnimator() : m_numberOfPassedCycles(0) { }
	void mainloop();
private:
    uint16_t m_numberOfPassedCycles;

    void nextGeneration();
};
