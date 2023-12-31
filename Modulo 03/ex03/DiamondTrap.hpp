#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "./FragTrap.hpp"
#include "./ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string Name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const &copy);
	~DiamondTrap();

	DiamondTrap &operator=(DiamondTrap const &assign);

	void	attack(const std::string& target);
	void	whoAmI();
};

#endif