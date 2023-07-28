#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "./ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& copy);
	ScavTrap& operator=(const ScavTrap& assign);

	void attack(const std::string& target);
	void guardGate(void);
};

#endif