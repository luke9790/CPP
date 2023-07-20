#include "Zombie.hpp"

Zombie::Zombie(void)
{
    return;
}

Zombie::~Zombie()
{
    std::cout << name << " has been destroyed." << std::endl;
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
    this->name = name;
}