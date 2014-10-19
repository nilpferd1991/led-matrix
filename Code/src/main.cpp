/**
 * @name led-matrix
 * @file main.cpp
 * @version 1.0.0
 * @author Markus Prim & Nils Braun
 * @brief TODO
 */

#include <avr/io.h>
#include <util/delay.h>

#include <Field.h>
#include <InterfaceLED.h>
#include <Animator.h>

int main() {
	// setup conways game of life
	InterfaceLED interface;

	Animator animator(new Field);
	animator.getField()->fillFieldMono(true);

	// Starting
	interface.showCycles(animator.getField(), 64);

	// Blank
	animator.getField()->fillFieldMono(false);

	// Main loop
	while(1) {
		interface.showCycles(animator.getNextGeneration(), 8);
	}
}
