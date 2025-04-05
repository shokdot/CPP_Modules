#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Default wrongCat constructor" << std::endl;
	this->type = "unknown";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "Copy wrongCat constructor" << std::endl;
	this->type = other.type;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor WrongCat" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat Sound" << std::endl;
}
