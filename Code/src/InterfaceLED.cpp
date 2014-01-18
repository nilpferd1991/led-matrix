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

void InterfaceLED::showField(const Field& field, const uint16_t waitingTime) {

	// loop through all columns
	for(uint8_t column = 0; column < field.getSizeX(); column++) {

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

		for(uint8_t row = 0; row < field.getSizeY(); row++) {
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

		for(uint16_t time = waitingTime; time > 0; time--) {
			_delay_us(1);
		}
	}

	// last clock
	PORTB |= (1 << InterfaceLED::m_clockPin);
	PORTB &= ~(1 << InterfaceLED::m_clockPin);

}
