#include "Character.hpp"

Character::Character() : name("nil")
{
	std::cout << "Character default constructor called." << std::endl;
	for (int i = 0; i < 4; ++i)
		this->slot[i] = NULL;
}

Character::Character(const std::string &name) : name(name)
{
	std::cout << "Character parametric constructor called." << std::endl;
	for (int i = 0; i < 4; ++i)
		this->slot[i] = NULL;
}

Character::Character(const Character &other) : name(other.name)
{
	std::cout << "Character copy constructor called." << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		if (other.slot[i])
		{
			delete this->slot[i];
			this->slot[i] = other.slot[i]->clone();
		}
		else
			this->slot[i] = NULL;
	}
}

Character &Character::operator=(const Character &rhs)
{
	std::cout << "Character copy assignment called." << std::endl;
	if (&rhs != this)
	{
		this->name = rhs.name;
		for (int i = 0; i < 4; i++)
		{
			delete this->slot[i];
			this->slot[i] = rhs.slot[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character destructor called." << std::endl;
	for (int i = 0; i < 4; ++i)
		delete this->slot[i];
}

const std::string &Character::getName() const { return (this->name); }

void Character::equip(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if (!this->slot[i])
		{
			this->slot[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		this->slot[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->slot[idx])
		this->slot[idx]->use(target);
}
