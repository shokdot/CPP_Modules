#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), m_name(name)
{
	std::cout << "DiamondTrap parametric constructor called" << std::endl;
	this->m_hit = FragTrap::m_hit;
	this->m_energy = ScavTrap::m_energy;
	this->m_attack = FragTrap::m_attack;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other), m_name(other.m_name)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	if (this == &rhs)
		return (*this);
	this->m_name = rhs.m_name;
	this->m_hit = rhs.m_hit;
	this->m_energy = rhs.m_energy;
	this->m_attack = rhs.m_attack;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
  std::cout << "DiamondTrap name is " << this->m_name << " ClapTrap name is " << ClapTrap::m_name << std::endl;
}
