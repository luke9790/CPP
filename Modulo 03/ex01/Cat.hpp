#ifndef CAT_HPP
#define CAT_HPP

#include "./Animal.hpp"
#include "./Brain.hpp"

class Cat : virtual public Animal
{
private:
	Brain* cervello;
public:
	Cat();
	Cat(std::string type);
	Cat(const Cat& copy);
	Cat& operator=(const Cat& assign);
	~Cat();

	std::string getType() const;
	void setType(std::string type);
	void makeSound() const;
};

#endif