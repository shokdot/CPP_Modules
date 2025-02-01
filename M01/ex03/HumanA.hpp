#pragma once
#include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	const Weapon *wep;
public:
	HumanA(std::string name, Weapon& wep);
	~HumanA();
	void attack() const;
	std::string get_name(void) const;
	void set_name(std::string& name);
};
