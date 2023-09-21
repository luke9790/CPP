#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
    std::cout << "Default Cure constructor called" << std::endl;
}

Cure::Cure(const Cure& other): AMateria("cure")
{
    std::cout << "Cure copy constructor called" << std::endl;
    *this = other;
}

Cure& Cure::operator=(const Cure& other)
{
    std::cout << "Cure assignment operator called" << std::endl;
    if (this != &other) {
        this->type = type;
    }
    return (*this);
}

Cure::~Cure()
{
    std::cout << "Cure destructor called" << std::endl;
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
    return(new Cure());
}