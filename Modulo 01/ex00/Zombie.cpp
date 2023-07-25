#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
	return;
}

Zombie::Zombie(const std::string& name) // si usa la copia per motivi di efficienza 
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << name << " has been destroyed." << std::endl;
}

void Zombie::announce() const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}