#include "./WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << "WrongAnimal constructor called for " << this->type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	this->type = copy.type;
	std::cout << "WrongAnimal copy constructor called for " << this->type << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& assign)
{
	this->type = assign.type;
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	return *this;
}

std::string WrongAnimal::getType() const
{
	std::cout << "WrongAnimal getType function called" << std::endl;
	return (this->type);
}

void WrongAnimal::setType(std::string type)
{
	std::cout << "WrongAnimal setType function called" << std::endl;
	this->type = type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Generic WrongAnimal noises" << std::endl;
}