/**
 * @name led-matrix
 * @file main.cpp
 * @version 1.0.0
 * @author Markus Prim & Nils Braun
 * @brief TODO
 */

#include <avr/io.h>
#include <util/delay.h>

#include <SnakeAnimator.h>

int main() {
	// setup the class to handle the animation
	SnakeAnimator animator;

	// Starting up: Show a blue screen
	animator.setFieldMono(true);
	animator.showCycles(64);
	animator.setFieldMono(false);

	// Main loop
	while(1) {
		animator.mainloop();
	}
}
