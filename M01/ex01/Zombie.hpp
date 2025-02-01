#pragma once
#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string m_name;
	public:
		Zombie();
		Zombie(std::string& name);
		~Zombie();
		void announce(void) const;
		void set_name(std::string name);
		std::string get_name(void) const;
};

Zombie* zombieHorde( int N, std::string name );
