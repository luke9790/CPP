#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream>

class ClapTrap
{
protected:
	std::string Name;
	int			HitPoints;
	int			EnergyPoints;
	int			AttackDmg;
	
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &copy);
	ClapTrap& operator=(ClapTrap const &assign);
	~ClapTrap();


	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};


#endif