#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N < 1)
		return NULL;
	Zombie *arr = new Zombie[N];
	for (int i = 0; i < N; ++i)
		arr[i].set_name(name);
	return arr;
}
