#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(const std::string &name) : m_name(name), m_hit(10), m_energy(10), m_attack(0)
{
	std::cout << "ClapTrap parametric constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : m_name(other.m_name), m_hit(other.m_hit), m_energy(other.m_energy), m_attack(other.m_attack)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (&rhs == this)
		return (*this);
	this->m_name = rhs.m_name;
	this->m_hit = rhs.m_hit;
	this->m_energy = rhs.m_energy;
	this->m_attack = rhs.m_attack;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->m_hit > 0 && this->m_energy > 0)
	{
		std::cout << "ClapTrap " << this->m_name << " attacks " << target << ", causing " << this->m_attack << " points of damage!" << std::endl;
		--this->m_energy;
	}
	else
		std::cout << "ClapTrap " << this->m_name << " can't attack! No energy or health left." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->m_hit != 0)
	{
		if (amount > static_cast<unsigned int>(this->m_hit))
			this->m_hit = 0;
		else
			this->m_hit -= amount;
		std::cout << "ClapTrap " << this->m_name << " taked " << amount << " amount of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->m_name << " can't damaged! No health left." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->m_hit != 0 && this->m_energy > 0)
	{
		--this->m_energy;
		int tmp = this->m_hit;
		tmp += amount;
		std::cout << "ClapTrap " << this->m_name << " be repaired " << amount << " amount of health!" << std::endl;
		this->m_hit = tmp < this->m_hit ? 10 : tmp;
	}
	else
		std::cout << "ClapTrap " << this->m_name << " can't be repaird! No energy or health left." << std::endl;
}

std::string ClapTrap::getName() const
{
      return m_name;
}

void ClapTrap::setName(const std::string &name)
{
     m_name = name;
}

int ClapTrap::getHit() const
{
      return m_hit;
}

void ClapTrap::setHit(int hit)
{
      m_hit = hit;
}

int ClapTrap::getEnergy() const
{
      return m_energy;
}

void ClapTrap::setEnergy(int energy)
{
      m_energy = energy;
}

int ClapTrap::getAttack() const
{
      return m_attack;
}

void ClapTrap::setAttack(int attack)
{
      m_attack = attack;
}