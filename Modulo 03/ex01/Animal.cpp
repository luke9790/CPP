#include "./Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "Animal constructor called for " << this->type << std::endl;
}

Animal::Animal(const Animal& copy)
{
	this->type = copy.type;
	std::cout << "Animal copy constructor called for " << this->type << std::endl;
}

Animal& Animal::operator=(const Animal& assign)
{
	this->type = assign.type;
	std::cout << "Animal assignation operator called" << std::endl;
	return *this;
}

std::string Animal::getType() const
{
	std::cout << "Animal getType function called" << std::endl;
	return (this->type);
}

void Animal::setType(std::string type)
{
	std::cout << "Animal setType function called" << std::endl;
	this->type = type;
}

void Animal::makeSound() const
{
	std::cout << "Generic animal noises" << std::endl;
}