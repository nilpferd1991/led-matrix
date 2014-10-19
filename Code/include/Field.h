/*
 * Field.h
 *
 *  Created on: 16.01.2014
 *      Author: mapr
 */
#pragma once

#include <Cell.h>
#include <stdint.h>

/**
 * This stores all the cells on the playground.
 */
class Field {
public:

	Field();
	virtual ~Field();

	Cell getField(const unsigned int& column, const unsigned int& row) const;
	void setField(const unsigned int& column, const unsigned int& row, const bool iniStatus);
	void fillFieldMono(bool iniStatus);
    void fillFieldRandom();
	const uint8_t getSizeX() const { return this->m_sizeX; };
	const uint8_t getSizeY() const { return this->m_sizeY; };

private:

	/**
	 * Size of x direction of the board.
	 */
	static const uint8_t m_sizeX = 8;

	/**
	 * Size of y direction of the board.
	 */
	static const uint8_t m_sizeY = 8;

	/**
	 * The board internally.
	 */
	Cell m_field[8][8]; // this is hardware limited for us.
};

