#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called." << std::endl;
	for (int i = 0; i < 4; ++i)
		this->slot[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource copy constructor called." << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		delete this->slot[i];
		this->slot[i] = other.slot[i]->clone();
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	std::cout << "MateriaSource copy assignment called." << std::endl;
	if (&rhs != this)
	{
		for (int i = 0; i < 4; ++i)
		{
			delete this->slot[i];
			this->slot[i] = rhs.slot[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called." << std::endl;
	for (int i = 0; i < 4; ++i)
		delete this->slot[i];
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!this->slot[i])
		{
			this->slot[i] = m;
			return;
		}
	}
}
AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->slot[i] && this->slot[i]->getType() == type)
			return this->slot[i]->clone();
	}
	return (nullptr);
}
