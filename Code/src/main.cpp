//============================================================================
// Name        : led-matrix
// Author      :
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <avr/io.h>
#include <util/delay.h>

#include <Field.h>
#include <InterfaceLED.h>

int main() {


	// this is hardware restricted
	const unsigned int nXLEDs(8);
	const unsigned int nYLEDs(8);

	// setup conways game of life
	Field field(nXLEDs, nYLEDs);
	field.fillFieldMono(false);

	InterfaceLED interface;


	DDRA = 0xFF;
	PORTA = 0xFF;

	while(1) {
		interface.showField(field);
	}
}
