#include "AMateria.hpp"

AMateria::AMateria() : type("null")
{
	std::cout << "AMateria default constructor called." << std::endl;
}

AMateria::AMateria(const std::string &type) : type(type)
{
	std::cout << "AMateria parametric constructor called." << std::endl;
}

AMateria::AMateria(const AMateria &other) : type(other.type)
{
	std::cout << "AMateria copy constructor called." << std::endl;
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	std::cout << "AMateria copy assignment called." << std::endl;
	if (&rhs != this)
		this->type = rhs.type;
	return (*this);
}

const std::string &AMateria::getType() const { return this->type; }

AMateria::~AMateria()
{
	std::cout << "AMateria detructor called." << std::endl;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "AMateria is " << target.getName() << std::endl;
}
