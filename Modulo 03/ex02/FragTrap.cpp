#include "./FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() 
{
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDmg = 30;
	std::cout << "FragTrap default constructor called" << std::endl; 
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap default destructor called for " << this->Name << std::endl; 
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDmg = 30;
	this->Name = name;
	std::cout << "FragTrap constructor called, named: " << this->Name << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
	this->HitPoints = copy.HitPoints;
	this->EnergyPoints = copy.EnergyPoints;
	this->AttackDmg = copy.AttackDmg;
	this->Name = copy.Name;
	std::cout << "FragTrap copy constructor called for "<< this->Name << std::endl; 
}

FragTrap& FragTrap::operator=(const FragTrap& assign)
{
	this->HitPoints = assign.HitPoints;
	this->EnergyPoints = assign.EnergyPoints;
	this->AttackDmg = assign.AttackDmg;
	this->Name = assign.Name;
	std::cout << "FragTrap assign operator constructor called" << std::endl;
	return *this;
}

void FragTrap::attack(const std::string& target)
{
	if(this->EnergyPoints > 0 && this->HitPoints > 0)
	{
		this->EnergyPoints--;
		std::cout << "FragTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDmg << " points of damage!" << std::endl;
		std::cout << "Now, FragTrap " << this->Name << " has " << this->EnergyPoints << " energy points left!" << std::endl;
	}
	else
		std::cout << "FragTrap " << this->Name << " cannot attack due to its condition!" << std::endl;
}


void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap is now requesting a high five!" << std::endl;
}