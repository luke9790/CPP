#include <iostream>
#include "./FragTrap.hpp"

int main()
{
    FragTrap fragtrap1("Frag1");
    FragTrap fragtrap2(fragtrap1);
    FragTrap fragtrap3("Frag2");

    fragtrap1.attack("nemico1");
    fragtrap2.takeDamage(100);
    fragtrap2.beRepaired(10);

    fragtrap2.attack("nemico2");
    fragtrap3.takeDamage(5);
    fragtrap3.attack("nemico3");
    fragtrap1.highFivesGuys();
    return 0;
}