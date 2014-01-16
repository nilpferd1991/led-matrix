/*
 * Cell.h
 *
 *  Created on: 16.01.2014
 *      Author: mapr
 */

#pragma once

/**
 * Simple cell class
 */
class Cell {

public:
	Cell();
	Cell(bool iniStatus);
	virtual ~Cell();

	bool getCellStatus() const;

private:
	/**
	 * Stores status of the cell.
	 */
	bool m_Status;
};
