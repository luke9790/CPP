#include "./HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
}

HumanB::~HumanB()
{
    return;
}

void    HumanB::attack()
{
    std::cout << name << " attacks with their " << arma->getType() << std::endl;
    return;
}

void    HumanB::setWeapon(Weapon& arma)
{
    this->arma = &arma;
}