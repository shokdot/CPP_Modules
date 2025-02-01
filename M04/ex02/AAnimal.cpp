#include "AAnimal.hpp"

AAnimal::AAnimal() : type("")
{
	std::cout << "AAnimal default constructor called!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : type(other.type)
{
	std::cout << "AAnimal copy constructor called!" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called!" << std::endl;
}

void AAnimal::setType(const std::string &type)
{
	this->type = type;
}

std::string AAnimal::getType(void) const
{
	return (this->type);
}
