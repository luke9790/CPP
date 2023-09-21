#include "Character.hpp"

Character::Character()
{
    std::cout << "Default Character constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        this->amateria[i] = NULL;
    }
}

Character::Character(std::string name)
{
    std::cout << "Character constructor with parameter called" << std::endl;
    this->name = name;
    for (int i = 0; i < 4; i++) {
        this->amateria[i] = NULL;
    }
}

Character::Character(const Character& other)
{
    std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        delete this->amateria[i];
    }
    *this = other;
}

Character& Character::operator=(const Character& other)
{
    std::cout << "Character assignment operator called" << std::endl;
    if ( this != &other) {
        for (int i = 0; i < 4; i++) {
            delete this->amateria[i];
        }
        this->name = other.name;
        for (int i = 0; i < 4; i++) {
            this->amateria[i] = other.amateria[i];
        }
    }
    return (*this);
}

Character::~Character()
{
    std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->amateria[i]) {
            delete this->amateria[i];
        }
    }
}

std::string const & Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++) {
        if (this->amateria[i] == NULL) {
            this->amateria[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (this->amateria[idx] != NULL) {
        this->amateria[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (this->amateria[idx] != NULL) {
        this->amateria[idx]->use(target);
    }
}