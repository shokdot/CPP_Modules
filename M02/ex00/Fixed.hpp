#pragma once
#include <string>
#include <iostream>

class Fixed
{
private:
	int value;
	static const int fractBit;

public:
	Fixed();
	Fixed(const Fixed &src);
	Fixed &operator=(const Fixed &rhs);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
};
