/*
 * InterfaceLED.cpp
 *
 *  Created on: 16.01.2014
 *      Author: nils
 */

#include "InterfaceLED.h"

void LEDMatrixHardware::writeRows(const Field* const field, uint8_t column) const {
	// Turn on writing on LED matrix
	enableWritingRows();
	for (uint8_t row = 0; row < field->getSizeY(); row++) {
		// one clock
		tickRows();
		// write 1 to data if cell is set
		setRow(field->getField(column, row).getCellStatus());
	}
	// why is the last clock needed?
	tickRows();
	setRow(false);
	// Turn off writing on LED matrix
	disableWritingRows();
}

void LEDMatrixHardware::writeColumn(uint8_t column) const {
	enableWritingColumns();
	// first write column index to shift registers
	for (uint8_t counter = 8; counter > 0; counter--) {
		// one clock
		tickColumns();
		// just one 1 on the column index
		setColumn(counter - 1 == column);
	}
	// why is the last clock needed?
	tickColumns();
	setColumn(false);
	// Turn off writing on LED matrix
	disableWritingColumns();
}

/**
 * Shows a field on the LED matrix.
 * Loops through the columns (by setting only one 1 for each column consecutively and the rest to zero)
 * and turns the rows to on, which have a turned on cell in this column.
 * Sends clock signals to the shift registers and turns STROBE off while writing (to prevent flickering).
 * @param field the field to be shown
 * @param waitingTime the waiting time between to columns in µs. It controls the brightness of the LEDs.
 * Values beyond approx. 2000 leed to flickering of the LEDs, values smaller than 100 make the LED too dark.
 */
void LEDMatrixHardware::showField(const Field * const field, const uint16_t waitingTime) const {

	// loop through all columns
	for(uint8_t column = 0; column < field->getSizeX(); column++) {

		disableOutput();
		writeColumn(column);
		writeRows(field, column);
		enableOutput();

		for(uint16_t time = waitingTime; time > 0; time--) {
			_delay_us(1);
		}
	}
}


void LEDMatrixHardware::showCycles(const Field * const field, uint16_t cycles) const {
	for(uint16_t t = 0; t < cycles; t++) {
		showField(field);
	}
}
