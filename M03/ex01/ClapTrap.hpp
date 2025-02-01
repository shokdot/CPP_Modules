#pragma once
#include <string>
#include <iostream>

class ClapTrap
{
protected:
	ClapTrap();
	std::string m_name;
	int m_hit;
	int m_energy;
	int m_attack;

public:
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &rhs);
	virtual ~ClapTrap();

	virtual void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

std::string getName() const;
void setName(const std::string &name);

int getHit() const;
void setHit(int hit);

int getEnergy() const;
void setEnergy(int energy);

int getAttack() const;
void setAttack(int attack);

};
