#include "Zombie.hpp"

Zombie::Zombie() : m_name("")
{
}

Zombie::Zombie(std::string &name) : m_name(name)
{
}

Zombie::~Zombie()
{
	std::cout << this->m_name << " : Bye.)" << std::endl;
}

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
	return (this->m_name);
}
