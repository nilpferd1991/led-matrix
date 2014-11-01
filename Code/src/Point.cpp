#include <Point.h>

bool operator==(Point const & lhs, Point const& rhs) {
	return lhs.m_column == rhs.m_column && lhs.m_row == rhs.m_row;
}
