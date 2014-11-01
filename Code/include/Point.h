#pragma once

#include <stdint.h>

class Point {
public:
	Point(uint8_t row, uint8_t column) : m_row(row), m_column(column) { }

	uint8_t m_row;
	uint8_t m_column;
};

bool operator==(Point const & lhs, Point const& rhs);
