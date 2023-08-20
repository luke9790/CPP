#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal
{
private:
	
protected:
	std::string type;
public:
	AAnimal();
	AAnimal(std::string type);
	AAnimal(const AAnimal& copy);
	AAnimal& operator=(const AAnimal& assign);
	virtual ~AAnimal();

	virtual std::string getType() const = 0;
	void setType(std::string type);
	virtual void makeSound() const = 0;
};

#endif