/*
 * Field.h
 *
 *  Created on: 16.01.2014
 *      Author: mapr
 */
#pragma once

#include <Cell.h>

/**
 * This stores all the cells on the playground.
 */
class Field {
public:

	Field(const unsigned int& sizeX, const unsigned int& sizeY);
	virtual ~Field();

	Cell getField(const unsigned int& column, const unsigned int& row) const;
	void fillFieldMono(bool iniStatus);

private:

	/**
	 * Size of x direction of the board.
	 */
	const unsigned int m_sizeX;

	/**
	 * Size of y direction of the board.
	 */
	const unsigned int m_sizeY;

	/**
	 * The board internally.
	 */
	Cell m_field[16][16]; // this is hardware limited for us.
};

