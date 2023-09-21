#pragma once
#include "AMateria.hpp"

class Cure: public AMateria
{
private:
    
public:
    Cure();
    Cure(const Cure& other);
    Cure& operator=(const Cure& other);
    ~Cure();
    void use(ICharacter& target);
    virtual AMateria* clone() const;
};