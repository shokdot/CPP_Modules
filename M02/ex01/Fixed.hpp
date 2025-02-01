#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
public:
	int value;
	static const int fractBit;

public:
	Fixed();
	Fixed(const int num);
	Fixed(const float fnum);
	Fixed(const Fixed &src);
	Fixed &operator=(const Fixed &rhs);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);
