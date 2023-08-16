#include "./Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type)
{
	this->type = type;
	std::cout << "Cat constructor called for " << this->type << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	this->type = copy.type;
	std::cout << "Cat copy constructor called for " << this->type << std::endl;
}

Cat& Cat::operator=(const Cat& assign)
{
	this->type = assign.type;
	std::cout << "Cat assignation operator called" << std::endl;
	return *this;
}

std::string Cat::getType() const
{
    return type;
}

void Cat::makeSound() const
{
	std::cout << "Miao Miao Miao" << std::endl;
}