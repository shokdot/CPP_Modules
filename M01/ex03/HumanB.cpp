#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), wep(nullptr){}

HumanB::~HumanB(){}

void HumanB::attack() const
{
	std::cout << this->get_name() << "attacks with their " << this->wep->getType() << "\n"; 
}

std::string HumanB::get_name(void) const
{
	return this->name;
}

void HumanB::set_name(std::string& name)
{
	this->name = name;
}

void HumanB::setWeapon(const Weapon& wep)
{
	this->wep = &wep;
}
