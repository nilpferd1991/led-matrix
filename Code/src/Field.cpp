/*
 * Field.cpp
 *
 *  Created on: 16.01.2014
 *      Author: mapr
 */

#include <Field.h>
#include <stdlib.h>     /* srand, rand */


/**
* Creates the playground with size x*y
* @param sizeX Number of LEDs in x
* @param sizeY Number of LEDs in y
* */
Field::Field(const uint8_t& sizeX, const uint8_t& sizeY) : m_sizeX(sizeX), m_sizeY(sizeY) {
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
 * @param column the column to be asked
 * @param row the row to be asked
 * @return Cell with adress [column, row]
 */
Cell Field::getField(const unsigned int& column, const unsigned int& row) const {
	return m_field[column][row];
}

void Field::setField(const unsigned int& column, const unsigned int& row, const bool iniStatus) {
	m_field[column][row] = iniStatus;
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

/**
 * Initializes the board randomly.
 */
void Field::fillFieldRandom() {
    for (unsigned int x = 0; x<m_sizeX; ++x) {
        for (unsigned int y = 0; y<m_sizeY; ++y) {
            m_field[x][y] = Cell(rand() % 2);
        }
    }
}
