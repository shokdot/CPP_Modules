#include "Zombie.hpp"

int main2()
{
	Zombie *z1 = new Zombie("AVA");
	Zombie *z2 = new Zombie("OPA");
	Zombie *z3 = new Zombie("SAKA");

	z1->announce();
	z2->announce();
	z3->announce();
	randomChump("LOLOZ");

	delete z1;
	delete z2;
	delete z3;
	return (2);

}

int main()
{
	main2();
	// system("leaks zombie");
}
