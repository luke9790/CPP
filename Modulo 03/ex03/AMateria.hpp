#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <string>
#include "./ICharacter.hpp"

class ICharacter;

class AMateria
{
private:
	
protected:
	std::string type;
	AMateria();
public:
	AMateria(std::string const & type);
	AMateria(AMateria const & other);
    AMateria& operator=(AMateria const & other);
	virtual ~AMateria();

	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif