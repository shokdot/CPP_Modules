#include "Zombie.hpp"

int t_main()
{
	int n = 4;
	Zombie *horde = zombieHorde(n, "Zomboid");

	horde[1].set_name("AVA");
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}

int	main()
{
	t_main();
	return (0);
}
