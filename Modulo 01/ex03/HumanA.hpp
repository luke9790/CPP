#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "./Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon* arma;

    public:
        HumanA(std::string name, Weapon& wpon);
        ~HumanA();

    void    attack();
};

#endif