/*
 * Field.cpp
 *
 *  Created on: 16.01.2014
 *      Author: mapr
 */

#include <Field.h>

Field::Field(unsigned int& sizeX, unsigned int& sizeY) : m_sizeX(sizeX), m_sizeY(sizeY) {
	// all cells on the field are dead
}

Field::~Field() {

}

Cell Field::getField() {
	return m_field;
}

void Field::fillFieldMono(bool iniStatus) {
	for (unsigned int x(0); x<m_sizeX; ++x) {
		for (unsigned int y(0); y<m_sizeY; ++y) {
			m_field[x][y] = Cell(iniStatus);
		}
	}
}
