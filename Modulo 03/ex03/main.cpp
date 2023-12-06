
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
    DiamondTrap rosso( "Rosso" );
    DiamondTrap blu( "Blu" );

    rosso.whoAmI();
    blu.whoAmI();

    rosso.attack( "the air" );
    rosso.takeDamage( 10 );
    rosso.beRepaired( 10 );

    return 0;
}