#include "./WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	this->type = type;
	std::cout << "WrongCat constructor called for " << this->type << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
	this->type = copy.type;
	std::cout << "WrongCat copy constructor called for " << this->type << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& assign)
{
	this->type = assign.type;
	std::cout << "WrongCat assignation operator called" << std::endl;
	return *this;
}

std::string WrongCat::getType() const
{
    return type;
}
