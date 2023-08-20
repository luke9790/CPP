#pragma once
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
private:
    AMateria* amateria[4];

public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource&  operator=(const MateriaSource& other);
    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};