/*
 * Field.h
 *
 *  Created on: 16.01.2014
 *      Author: mapr
 */
#pragma once

#include <Cell.h>

class Field {
public:
	Field(unsigned int& sizeX, unsigned int& sizeY);
	virtual ~Field();

	Cell getField();
	void fillFieldMono(bool iniStatus);

private:
	unsigned int m_sizeX;
	unsigned int m_sizeY;
	Cell m_field[16][16]; // this is hardware limited for us.
};

