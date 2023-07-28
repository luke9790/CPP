#include <iostream>
#include "./ScavTrap.hpp"

int main()
{
    ScavTrap eroe("Mazinga");
    std::string nemico = "Dracula";
    eroe.attack(nemico);
    eroe.takeDamage(5);
    eroe.beRepaired(4);
    eroe.guardGate();

    return 0;
}