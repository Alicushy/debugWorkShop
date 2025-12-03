#include "Point.h"
#include <iostream>

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
	// Fixed: Allocate new memory (Deep copy)
	_coord = new int[2];
	_coord[0] = other._coord[0];
	_coord[1] = other._coord[1];
}

Point::~Point()
{
	delete[] _coord;  // Fixed: delete[] instead of delete
}

Point& Point::operator=(const Point& other)
{
	if (this != &other)  // Fixed: check for self-assignment
	{
		delete[] _coord;  // Fixed: delete[] instead of delete
		_coord = new int[2];
		_coord[0] = other._coord[0];
		_coord[1] = other._coord[1];
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