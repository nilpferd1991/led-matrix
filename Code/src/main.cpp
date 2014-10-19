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
	
	DDRD = 0xFF;
	PORTD = 0xFF;
	
	// setup conways game of life
	Field field;
	field.fillFieldMono(true);

	InterfaceLED interface(&field);
	Evolution evolve;

	interface.waitCycles(64*7);
	PORTD = 0x0;

	while(1) {
		interface.waitCycles(16);
		field = evolve.evolve(field);
	}
}
