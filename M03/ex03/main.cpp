#include "DiamondTrap.hpp"

int main() {
{
    std::cout << "\n--- Testing ClapTrap ---\n";
    ClapTrap clap("ClapMaster");
    clap.attack("target_1");
    clap.takeDamage(30);
    clap.beRepaired(20);
}
{
    std::cout << "\n--- Testing ScavTrap ---\n";
    ScavTrap scav("ScavMaster");
    scav.attack("target_2");
    scav.takeDamage(40);
    scav.beRepaired(15);
    scav.guardGate();
}
{
    std::cout << "\n--- Testing FragTrap ---\n";
    FragTrap frag("FragMaster");
    frag.attack("target_3");
    frag.takeDamage(50);
    frag.beRepaired(30);
    frag.highFivesGuys();
}
{
    std::cout << "\n--- Testing DiamondTrap ---\n";
    DiamondTrap diamond("DiamondMaster");
    diamond.attack("target_4");        // ScavTrap attack
    diamond.takeDamage(60);           // ClapTrap takeDamage
    diamond.beRepaired(25);           // ClapTrap beRepaired
    diamond.guardGate();              // ScavTrap functionality
    diamond.highFivesGuys();          // FragTrap functionality
    diamond.whoAmI();                 // Unique DiamondTrap method

}
    return 0;
}
