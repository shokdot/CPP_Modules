#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "FragTrap parameter constructor called" << std::endl;
	this->m_hit = 100;
	this->m_energy = 100;
	this->m_attack = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "FragTrap copy assignment operator called." << std::endl;
	this->m_name = rhs.m_name;
	this->m_hit = rhs.m_hit;
	this->m_energy = rhs.m_energy;
	this->m_attack = rhs.m_attack;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->m_name << " high five Guys!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}
