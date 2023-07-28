#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "./ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:
	
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &copy);
	ScavTrap& operator=(ScavTrap const &assign);

	void attack(const std::string& target);
	void guardGate(void);
};

#endif