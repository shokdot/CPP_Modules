#include "Point.hpp"

Fixed my_mod(Fixed value)
{
	if (value < 0)
		return (value * -1);
	return (value);
}

Fixed count_area(const Point a, const Point b, const Point c)
{
	return (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed ABC = my_mod(count_area(a, b, c)) / 2;
	Fixed PAB = my_mod(count_area(point, a, b)) / 2;
	Fixed PBC = my_mod(count_area(point, b, c)) / 2;
	Fixed PCA = my_mod(count_area(point, c, a)) / 2;

	return (ABC == (PAB + PBC + PCA));
}
