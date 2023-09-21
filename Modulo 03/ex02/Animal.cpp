#include "./Animal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(std::string type)
{
	this->type = type;
	std::cout << "AAnimal constructor called for " << this->type << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy)
{
	this->type = copy.type;
	std::cout << "AAnimal copy constructor called for " << this->type << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& assign)
{
	this->type = assign.type;
	std::cout << "AAnimal assignation operator called" << std::endl;
	return *this;
}

std::string AAnimal::getType() const
{
	std::cout << "AAnimal getType function called" << std::endl;
	return (this->type);
}

void AAnimal::setType(std::string type)
{
	std::cout << "AAnimal setType function called" << std::endl;
	this->type = type;
}

void AAnimal::makeSound() const
{
	std::cout << "Generic animal noises" << std::endl;
}