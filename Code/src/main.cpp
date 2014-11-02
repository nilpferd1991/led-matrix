/**
 * @name led-matrix
 * @file main.cpp
 * @version 1.0.0
 * @author Markus Prim & Nils Braun
 * @brief TODO
 */

#include <SnakeAnimator.h>

int main() {
	// setup the class to handle the animation
	SnakeAnimator animator;
	animator.flashInTheBeginning();

	// Main loop
	while(1) {
		animator.mainloop();
	}
}
