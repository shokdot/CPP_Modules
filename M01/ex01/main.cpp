#include "Zombie.hpp"

int	main(void)
{
	int		n;
	Zombie	*horde;

	n = 4;
	horde = zombieHorde(n, "Zomboid");
	horde[1].set_name("AVA");
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
