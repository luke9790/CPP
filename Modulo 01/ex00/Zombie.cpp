#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
    // Default constructor
    return;
}

Zombie::Zombie(const std::string& name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    // Destructor
    std::cout << name << " has been destroyed." << std::endl;
}

void Zombie::announce() const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}