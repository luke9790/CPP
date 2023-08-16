#include "./Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	this->type = type;
	std::cout << "Dog constructor called for " << this->type << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	this->type = copy.type;
	std::cout << "Dog copy constructor called for " << this->type << std::endl;
}

Dog& Dog::operator=(const Dog& assign)
{
	this->type = assign.type;
	std::cout << "Dog assignation operator called" << std::endl;
	return *this;
}

std::string Dog::getType() const
{
    return type;
}

void Dog::makeSound() const
{
	std::cout << "Bau Bau Bau" << std::endl;
}