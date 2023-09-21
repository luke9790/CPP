#include "./Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	this->cervello = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
	delete cervello;
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type)
{
	this->type = type;
	this->cervello = new Brain();
	std::cout << "Dog constructor called for " << this->type << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	this->type = copy.type;
	this->cervello = new Brain(*copy.cervello);
	std::cout << "Dog copy constructor called for " << this->type << std::endl;
}

Dog& Dog::operator=(const Dog& assign)
{
	this->type = assign.type;
	delete this->cervello;
	this->cervello = new Brain(*assign.cervello);
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