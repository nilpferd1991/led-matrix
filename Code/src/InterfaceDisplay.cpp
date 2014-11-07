/*
 * InterfaceLED.cpp
 *
 *  Created on: 16.01.2014
 *      Author: nils
 */

#include "InterfaceDisplay.h"
#include <iostream>

void LEDMatrixHardware::showField(const Field * const field, const uint16_t waitingTime) const {

	// loop through all columns
	for(uint8_t column = 0; column < field->getSizeX(); column++) {
		for(uint8_t row = 0; row < field->getSizeY(); row++) {
			std::cout << field->getCell(column, row) ? "0" : "1";
		}
		std::cout << "\n";
	}
}


void LEDMatrixHardware::showCycles(const Field * const field, uint16_t cycles) const {
	for(uint16_t t = 0; t < cycles; t++) {
		showField(field);
	}
}
