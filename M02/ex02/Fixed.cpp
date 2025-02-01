#include "Fixed.hpp"

const int Fixed::fractBit = 8;

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int num)
{
	this->value = num << fractBit;
}

Fixed::Fixed(const float fnum)
{
	this->value = roundf(fnum * (1 << fractBit));
}

Fixed::Fixed(const Fixed &src)
{
	this->value = src.value;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	if (&rhs == this)
		return (*this);
	this->value = rhs.value;
	return (*this);
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

int Fixed::toInt(void) const
{
	return (this->value >> fractBit);
}

float Fixed::toFloat(void) const
{
	return (this->value / float(1 << fractBit));
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->toFloat() > other.toFloat());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->toFloat() < other.toFloat());
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->toFloat() != other.toFloat());
}

Fixed Fixed::operator+(const Fixed &other)
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other)
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other)
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other)
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed &Fixed::operator++(void)
{
	++this->value;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	--this->value;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++this->value;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--this->value;
	return (tmp);
}

Fixed Fixed::min(Fixed &one, Fixed &two)
{
	return (one < two ? one : two);
}

const Fixed Fixed::min(const Fixed &one, const Fixed &two)
{
	return (one < two ? one : two);
}

Fixed Fixed::max(Fixed &one, Fixed &two)
{
	return (one > two ? one : two);
}

const Fixed Fixed::max(const Fixed &one, const Fixed &two)
{
	return (one > two ? one : two);
}
