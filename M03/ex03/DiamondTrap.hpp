#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	DiamondTrap();
	std::string m_name;

public:
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap &operator=(const DiamondTrap &rhs);
	~DiamondTrap();

	void whoAmI();
    using ScavTrap::attack;
};
