#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
private:
	
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal& copy);
	WrongAnimal& operator=(const WrongAnimal& assign);
	virtual ~WrongAnimal();

	virtual std::string getType() const;
	void setType(std::string type);
	virtual void makeSound() const;
};

#endif