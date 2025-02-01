#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	// Create ClapTrap and ScavTrap instances
	ClapTrap clap("Clappy");
	ScavTrap scav("Scavvy");

	std::cout << "\n--- ATTACK DEMONSTRATION ---\n";
	clap.attack("Scavvy");
	scav.attack("Clappy");

	std::cout << "\n--- DAMAGE AND REPAIR ---\n";
	scav.takeDamage(30);
	scav.beRepaired(20);

	std::cout << "\n--- SCAVTRAP SPECIAL MODE ---\n";
	scav.guardGate();

	std::cout << "\n--- COPY & ASSIGNMENT ---\n";
	ScavTrap scavCopy(scav);	  // Copy constructor
	ScavTrap scavAssigned = scav; // Assignment operator

	std::cout << "\n--- EDGE CASES ---\n";
	scav.takeDamage(100);  // Exceeding health limit
	scav.attack("Clappy"); // Should not attack when health is 0
	scav.beRepaired(10);   // Should not repair when health is 0

	return 0;
}
