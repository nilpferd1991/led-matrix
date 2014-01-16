/*
 * InterfaceLED.cpp
 *
 *  Created on: 16.01.2014
 *      Author: nils
 */

#include "InterfaceLED.h"

InterfaceLED::InterfaceLED() {
	// initialize pins
	DDRB = 0xFF;
	PORTB = 0;

}

InterfaceLED::~InterfaceLED() {
	// TODO Auto-generated destructor stub
}

void InterfaceLED::showField(Field field) {

	// loop through all columns
	for(uint8_t column = 0; column < 8; column++) {

		// Turn of writing on LED matrix
		PORTB &= ~(1 << InterfaceLED::m_strobePin);

		// first write column index to shift registers
		for(uint8_t counter = 8; counter > 0; counter--) {
			// one clock
			PORTB |= (1 << InterfaceLED::m_clockPin);
			PORTB &= ~(1 << InterfaceLED::m_clockPin);
			// just one 1 on the column index
			if(counter - 1 == column) {
				PORTB |= (1 << InterfaceLED::m_dataPin);
			}
			else
			{
				PORTB &= ~(1 << InterfaceLED::m_dataPin);
			}
		}

		for(uint8_t row = 0; row < 8; row++) {
			// one clock
			PORTB |= (1 << InterfaceLED::m_clockPin);
			PORTB &= ~(1 << InterfaceLED::m_clockPin);

			// write 1 to data if cell is set
			if(field.getField(column,row).getCellStatus() == true) {
				PORTB |= (1 << InterfaceLED::m_dataPin);
			}
			else {
				PORTB &= ~(1 << InterfaceLED::m_dataPin);
			}
		}


		// Turn on writing on LED matrix
		PORTB |= (1 << InterfaceLED::m_strobePin);

		_delay_ms(InterfaceLED::m_waitingTime);

	}

	// last clock
	PORTB |= (1 << InterfaceLED::m_clockPin);
	PORTB &= ~(1 << InterfaceLED::m_clockPin);

}
