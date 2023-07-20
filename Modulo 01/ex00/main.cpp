#include "Zombie.hpp"

int main()
{
    // Testing newZombie function
    Zombie* zombie1 = Zombie::newZombie("Bob");
    zombie1->announce();
    delete zombie1; // Don't forget to delete the dynamically allocated zombie.

    // Testing randomChump function
    Zombie::randomChump("Alice");

    return 0;
}