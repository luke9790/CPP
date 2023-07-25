#include "Zombie.hpp"

int main()
{
	Zombie* zombie1 = Zombie::newZombie("Bob");
	zombie1->announce();
	delete zombie1; 

	Zombie::randomChump("Alice");

	return 0;
}