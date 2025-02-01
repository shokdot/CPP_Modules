#pragma once
#include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	const Weapon *wep;
public:
	HumanB(std::string name);
	~HumanB();
	void attack() const;
	std::string get_name(void) const;
	void set_name(std::string& name);
	void setWeapon(const Weapon& wep);
};
