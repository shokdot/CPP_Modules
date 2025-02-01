#pragma once
#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;

public:
	Point();
	Point(const float x, const float y);
	Point(const Point &other);
	Point &operator=(const Point &rhs);
	~Point();

	float getX(void) const;
	float getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
