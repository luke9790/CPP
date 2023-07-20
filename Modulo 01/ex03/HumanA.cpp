#include "./HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& wpon)
{
    this->name = name;
    arma = &wpon;
}

HumanA::~HumanA()
{
    return;
}

void    HumanA::attack()
{
    std::cout << name << " attacks with their " << arma->getType() << std::endl;
    return;
}