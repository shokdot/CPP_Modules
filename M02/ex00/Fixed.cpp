#include "Fixed.hpp"

const int Fixed::fractBit = 8;

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
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
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}
