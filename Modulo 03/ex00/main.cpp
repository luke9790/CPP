#include <iostream>
#include "./ClapTrap.hpp"

int main()
{
    ClapTrap eroe("Mazinga");
    std::string nemico = "Dracula";
    eroe.attack(nemico);
    eroe.takeDamage(5);
    eroe.beRepaired(4);
    eroe.takeDamage(9);
    eroe.beRepaired(4);

    return 0;
}