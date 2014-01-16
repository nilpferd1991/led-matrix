/*
 * Cell.h
 *
 *  Created on: 16.01.2014
 *      Author: mapr
 */

#pragma once

class Cell {
public:
	Cell();
	Cell(bool iniStatus);
	virtual ~Cell();

	bool getCellStatus() const;

private:
	bool m_Status;
};
