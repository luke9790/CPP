#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "./ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
	
public:
	FragTrap();
	~FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap const &copy);
	FragTrap& operator=(FragTrap const &assign);

	void attack(const std::string& target);
	void highFivesGuys(void);
};

#endif