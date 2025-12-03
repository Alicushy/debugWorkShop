#include "Point.h"
#include <iostream>
#include <cstring>

Point::Point()
{
	_coord = new int[2];
	_coord[0] = _coord[1] = 0;
}

Point::Point(int x, int y)
{
	_coord = new int[2];
	_coord[0] = x;
	_coord[1] = y;
}

Point::Point(const Point& other)
{
	// FIX: Perform deep copy instead of shallow copy

	_coord = new int[2];
	_coord[0] = other._coord[0];
	_coord[1] = other._coord[1];
}

Point::~Point()
{
	delete[] _coord;  // Use delete[] for arrays
}

Point& Point::operator=(const Point& other)
{
	// Check for self-assignment
	if (this != &other)
	{
		delete[] _coord;  // Use delete[] for arrays
		_coord = new int[2];
		// FIX: Copy 2 integers (8 bytes), not 2 bytes
		memcpy(_coord, other._coord, 2 * sizeof(int));
	}
	return *this;
}

int Point::getX() const
{
	return _coord[0];
}

int Point::getY() const
{
	return _coord[1];
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << "(" << p._coord[0] << "," << p._coord[1] << ")";
	return os;
}