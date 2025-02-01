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
	~Fixed();

	bool operator>(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	Fixed &operator=(const Fixed &rhs);
	Fixed operator+(const Fixed &other);
	Fixed operator-(const Fixed &other);
	Fixed operator*(const Fixed &other);
	Fixed operator/(const Fixed &other);

	Fixed &operator++(void);
	Fixed &operator--(void);

	Fixed operator++(int);
	Fixed operator--(int);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

	static Fixed min(Fixed &one, Fixed &two);
	static const Fixed min(const Fixed &one, const Fixed &two);

	static Fixed max(Fixed &one, Fixed &two);
	static const Fixed max(const Fixed &one, const Fixed &two);
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);
