#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called." << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << "Ice copy constructor called." << std::endl;
}

Ice &Ice::operator=(const Ice &rhs)
{
	std::cout << "Ice copy assignment called." << std::endl;
	if (&rhs != this)
		this->type = rhs.type;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice destructor called." << std::endl;
}
AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
