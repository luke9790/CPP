#include "./Weapon.hpp"

Weapon::Weapon(void)
{
    return ;
}

Weapon::Weapon(std::string type)
{
    this->type = type;
}

Weapon::~Weapon(void)
{
    return ;
}

const std::string& Weapon::getType()
{
    return ((std::string&)type);
}

void Weapon::setType(std::string newname)
{
    type = newname;
}