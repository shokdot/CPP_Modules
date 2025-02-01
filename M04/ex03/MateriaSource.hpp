#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *slot[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &rhs);
	~MateriaSource();

	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);
};
