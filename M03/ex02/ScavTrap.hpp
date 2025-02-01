#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	ScavTrap();

public:
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &rhs);
	~ScavTrap();

	void attack(const std::string &target);
	void guardGate() const;
};
