/*
 * Cell.cpp
 *
 *  Created on: 16.01.2014
 *      Author: mapr
 */

#include <Cell.h>


/**
 * Cell constructor with no argument.
 * Cells produced this way are always dead.
* */
Cell::Cell() : m_Status(false) {
	// always dead cells
}

/**
 * Cell constructor with one argument.
 * Cells produced this way are dead(false) or alive(true).
 */
Cell::Cell(bool iniStatus) : m_Status(iniStatus) {

}

/**
 * Cell default destructor.
 */
Cell::~Cell() {

}

/**
 * Returns current state of the cell.
 * @return alive(true) or dead(false)
 */
bool Cell::getCellStatus() const {
	return m_Status;
}
