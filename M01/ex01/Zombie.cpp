#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::Zombie(std::string& name)
{
	set_name(name);
}

Zombie::~Zombie(){}

void Zombie::announce(void) const
{
	std::cout << this->get_name() << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::set_name(std::string name)
{
	this->m_name = name;
}

std::string Zombie::get_name(void) const
{
	return this->m_name;
}
