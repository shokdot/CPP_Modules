#include "Point.hpp"

int main()
{
	// Point p1(1, 1);
	// Point p2(4, 1);
	// Point p3(2, 5);
	// Point point(5, 3);
	// false

	Point p1(5, 0);
	Point p2(0, 0);
	Point p3(2, 5);
	Point point(3, 2);
	// true

	// Point p1(1, 1);
	// Point p2(4, 1);
	// Point p3(2, 5);
	// Point point(3, 3);
	// false
	std::cout << bsp(p1, p2, p3, point) << std::endl;
}
