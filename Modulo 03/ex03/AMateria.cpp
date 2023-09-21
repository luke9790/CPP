#include "AMateria.hpp"

AMateria::AMateria(): type("")
{
    std::cout << "Default AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
    std::cout << "AMateria constructor with parameter called" << std::endl;
    this->type = type;
}

AMateria::AMateria(AMateria const & other)
{
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = other;
}

AMateria& AMateria::operator=(AMateria const & other)
{
    std::cout << "AMateria assignment operator called" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
    return (this->type);
}

void    AMateria::use( ICharacter& target )
{
    std::cout << "AMateria " << this->type << " used on " << target.getName() << std::endl;
}