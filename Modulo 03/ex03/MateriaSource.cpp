#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "Default MateriaSource constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        this->amateria[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
    *this = other;
}

MateriaSource&  MateriaSource::operator=(const MateriaSource& other)
{
    std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
            this->amateria[i] = other.amateria[i];
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource Destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->amateria[i]) {
            delete this->amateria[i];
        }
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++) {
        if (this->amateria[i] == NULL) {
            this->amateria[i] = m;
            return ;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++) {
        if (this->amateria[i] && this->amateria[i]->getType() == type) {
            return (this->amateria[i]->clone());
        }
    }
    return NULL;
}
