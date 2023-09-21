#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "./WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:

public:
	WrongCat();
	WrongCat(std::string type);
	WrongCat(const WrongCat& copy);
	WrongCat& operator=(const WrongCat& assign);
	~WrongCat();

	std::string getType() const;
	void setType(std::string type);
	// void makeSound() const;
};

#endif