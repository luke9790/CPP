#include "./Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& copy)
{
	int i = 0;
    while (i < 100)
	{
        ideas[i] = copy.ideas[i]; // Utilizza l'operatore di assegnazione delle stringhe per copiare i contenuti
        ++i;
    }
	std::cout << "Brain copy constructor called for " << this->ideas << std::endl;
}

Brain& Brain::operator=(const Brain& assign)
{
	if (this != &assign) 
	{
        int i = 0;
        while (i < 100) 
		{
            ideas[i] = assign.ideas[i]; // Utilizza l'operatore di assegnazione delle stringhe per copiare i contenuti
            ++i;
        }
    }
	std::cout << "Brain assignation operator called" << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}