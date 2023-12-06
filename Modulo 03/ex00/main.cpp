#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap clap("Blu");
    clap.attack("Rosso");
    clap.takeDamage(15);
    clap.attack("Rosso");
    clap.beRepaired(1);
    return 0;
}