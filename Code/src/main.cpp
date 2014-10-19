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
#include <Evolution.h>

int main() {
	// setup conways game of life
	InterfaceLED interface(new Field);
	interface.getField()->fillFieldMono(true);
	Evolution evolve;

	// Starting
	interface.showCycles(64);

	// Mainloop
	while(1) {
		interface.showCycles(8);
	}
}
