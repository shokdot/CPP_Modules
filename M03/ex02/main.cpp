#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	// Creating instances
	ClapTrap clap("Clappy");
	ScavTrap scav("Scavvy");
	FragTrap frag("Fraggy");

	std::cout << "\n--- ATTACK DEMONSTRATION ---\n";
	clap.attack("Scavvy");
	scav.attack("Clappy");
	frag.attack("Scavvy");

	std::cout << "\n--- DAMAGE AND REPAIR ---\n";
	scav.takeDamage(30);
	frag.takeDamage(50);
	frag.beRepaired(40);

	std::cout << "\n--- SCAVTRAP & FRAGTRAP SPECIAL MODES ---\n";
	scav.guardGate();
	frag.highFivesGuys();

	std::cout << "\n--- COPY & ASSIGNMENT ---\n";
	FragTrap fragCopy(frag);	  // Copy constructor
	FragTrap fragAssigned = frag; // Assignment operator

	std::cout << "\n--- EDGE CASES ---\n";
	frag.takeDamage(200);  // Exceeding health limit
	frag.attack("Clappy"); // Should not attack when health is 0
	frag.beRepaired(10);   // Should not repair when health is 0

	return 0;
}
