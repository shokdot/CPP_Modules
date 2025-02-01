#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& wep) : name(name), wep(&wep){}

HumanA::~HumanA(){}

void HumanA::attack() const
{
	std::cout << this->get_name() << "attacks with their " << this->wep->getType() << "\n"; 
}

std::string HumanA::get_name(void) const
{
	return this->name;
}

void HumanA::set_name(std::string& name)
{
	this->name = name;
}
