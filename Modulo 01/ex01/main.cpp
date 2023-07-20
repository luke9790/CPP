#include "Zombie.hpp"

int main()
{
    Zombie *orda = zombieHorde(5, "Robbie");
    int i = 0;
    while(i < 5)
    {
        orda[i].announce();
        i++;
    }
    delete[] orda;
    return 0;
}