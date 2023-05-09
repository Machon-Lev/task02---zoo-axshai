#include "Location.h"

std::ostream& operator<<(std::ostream& os, const Location& loc)
{
	os << "row: " << loc.row << " column: " << loc.column << "\n";
	return os;
}

Location operator+(const Location& loc1, const Location& loc2)
{
	return Location{ loc1.row + loc2.row, loc1.column + loc2.column };
}

Location& operator+=(Location& loc1, const Location& loc2)
{
	loc1.row += loc2.row;
	loc1.column += loc2.column;
	return loc1;
}

bool operator==(const Location& loc1, const Location& loc2)
{
	return loc1.row == loc2.row && loc1.column == loc2.column;
}

bool operator!=(const Location& loc1, const Location& loc2)
{
	return !(loc1 == loc2);
}