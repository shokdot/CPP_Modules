#include "ClapTrap.hpp"

int main()
{
	// Create ClapTrap instances
	ClapTrap clap1("Alpha");
	ClapTrap clap2("Beta");

	// Attack and damage demonstration
	clap1.attack("Beta");
	clap2.takeDamage(clap1.getAttack());

	// Repair demonstration
	clap2.beRepaired(5);

	// Copy constructor demonstration
	ClapTrap clap3(clap1);
	clap3.attack("Beta");

	// Assignment operator demonstration
	clap3 = clap2;
	clap3.attack("Alpha");

	// Edge cases
	clap1.takeDamage(20); // Exceeding health limit
	clap1.attack("Beta"); // Should not attack when health is 0
	clap1.beRepaired(5);  // Should not repair when health is 0

	return 0;
}
