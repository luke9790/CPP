#include "./DiamondTrap.hpp"

int main()
{
	DiamondTrap eroe1;
	DiamondTrap eroe2("Batman");
	
	eroe1.attack("Joker");
	eroe1.whoAmI();
	eroe2.whoAmI();
	eroe2.beRepaired(120);
	eroe2.highFivesGuys();
	eroe2.takeDamage(99);
    return 0;
}