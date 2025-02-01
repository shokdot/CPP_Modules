#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}
Dog::Dog(const Dog &other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = other.type;
}
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}
Dog &Dog::operator=(const Dog &rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Bark Bark Bark!" << std::endl;
}
