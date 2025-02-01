#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Default wrongAnimal constructor" << std::endl;
	this->type = "unknown";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "Copy wrongAnimal constructor" << std::endl;
	this->type = other.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor wrongAnimal" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal Sound" << std::endl;
}

void WrongAnimal::setType(const std::string &type)
{
	this->type = type;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}
