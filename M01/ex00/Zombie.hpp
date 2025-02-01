#pragma once
#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string m_name;
	public:
		Zombie(const std::string& name);
		~Zombie();
		void announce(void) const;
		void set_name(const std::string& name);
		std::string get_name(void) const;
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );
