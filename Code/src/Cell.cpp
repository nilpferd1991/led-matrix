/*
 * Cell.cpp
 *
 *  Created on: 16.01.2014
 *      Author: mapr
 */

#include <Cell.h>

Cell::Cell() : m_Status(false) {
	// always dead cells
}

/** Simple cell class
 * status defined on initialization
 */
Cell::Cell(bool iniStatus) : m_Status(iniStatus) {

}

Cell::~Cell() {
// TODO Auto-generated destructor stub
}

bool Cell::getCellStatus() const
{
	return m_Status;
}
