#ifndef DOG_HPP
#define DOG_HPP

#include "./Animal.hpp"

class Dog : virtual public Animal
{
private:

public:
	Dog();
	Dog(std::string type);
	Dog(const Dog& copy);
	Dog& operator=(const Dog& assign);
	~Dog();

	std::string getType() const;
	void setType(std::string type);
	void makeSound() const;
};

#endif