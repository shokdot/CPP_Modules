#include "Weapon.hpp"

Weapon::Weapon(const std::string& type): type(type){}

std::string Weapon::getType(void) const
{
	return this->type;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
