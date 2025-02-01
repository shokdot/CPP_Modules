#include "Animal.hpp"

Animal::Animal() : type("")
{
	std::cout << "Animal default constructor called!" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Animal copy constructor called!" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called!" << std::endl;
}

void Animal::setType(const std::string &type)
{
	this->type = type;
}

std::string Animal::getType(void) const
{
	return (this->type);
}

void Animal::makeSound() const {}
