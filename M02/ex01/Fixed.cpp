#include "Fixed.hpp"

const int Fixed::fractBit = 8;

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = num << fractBit;
}

Fixed::Fixed(const float fnum)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(fnum * (1 << fractBit));
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = src.value;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	if (&rhs == this)
		return (*this);
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = rhs.value;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

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
