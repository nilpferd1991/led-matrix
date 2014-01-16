/*
 * Field.cpp
 *
 *  Created on: 16.01.2014
 *      Author: mapr
 */

#include <Field.h>

/**
* Creates the playground with size x*y
* @param sizeX Number of LEDs in x
* @param sizeY Number of LEDs in y
* */
Field::Field(const unsigned int& sizeX, const unsigned int& sizeY) : m_sizeX(sizeX), m_sizeY(sizeY) {
	// all cells on the field are dead
}

Field::~Field() {
	for (unsigned int x(0); x<m_sizeX; ++x) {
		for (unsigned int y(0); y<m_sizeY; ++y) {
			m_field[x][y].~Cell();
		}
	}
}

/**
 * Returns the internally stored field. This is needed by the led lightup routine.
 * @return x*y size array of type Cell
 * TODO: Fix return type
 */
Cell Field::getField() const {
	return m_field;
}

/**
 * Sets the bord with only living or dead cells.
 * @param iniStatus true=living, false=dead cell
 */
void Field::fillFieldMono(bool iniStatus) {
	for (unsigned int x(0); x<m_sizeX; ++x) {
		for (unsigned int y(0); y<m_sizeY; ++y) {
			m_field[x][y] = Cell(iniStatus);
		}
	}
}
