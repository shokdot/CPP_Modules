#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "ScavTrap parameter constructor called" << std::endl;
	this->m_hit = 100;
	this->m_energy = 50;
	this->m_attack = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	if (this == &rhs)
		return (*this);
	std::cout << "ScavTrap copy assignment operator called." << std::endl;
	this->m_name = rhs.m_name;
	this->m_hit = rhs.m_hit;
	this->m_energy = rhs.m_energy;
	this->m_attack = rhs.m_attack;
	return (*this);
}

void ScavTrap::guardGate() const
{
	std::cout << "ScavTrap " << this->m_name << " is now in gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->m_hit > 0 && this->m_energy > 0)
	{
		std::cout << "ScavTrap " << this->m_name << " attacks " << target << ", causing " << this->m_attack << " points of damage !" << std::endl;
		--this->m_energy;
	}
	else
		std::cout << "ScavTrap " << this->m_name << " can't attack! No energy or health left." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}
