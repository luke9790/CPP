#include "./ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDmg = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << this->Name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDmg = 20;
	this->Name = name;
	std::cout << "ScavTrap constructor called, named: " << this->Name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
	this->AttackDmg = copy.AttackDmg;
	this->EnergyPoints = copy.EnergyPoints;
	this->HitPoints = copy.HitPoints;
	this->Name = copy.Name;
	std::cout << "ScavTrap copy constructor called for " << this->Name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& assign)
{
	this->AttackDmg = assign.AttackDmg;
	this->EnergyPoints = assign.EnergyPoints;
	this->HitPoints = assign.HitPoints;
	this->Name = assign.Name;
	std::cout << "Assignation operator called" << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if(this->EnergyPoints > 0 && this->HitPoints > 0)
	{
		this->EnergyPoints--;
		std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDmg << " points of damage! ";
		std::cout << "Now, ScavTrap " << this->Name << " has " << this->EnergyPoints << " energy points left!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->Name << " cannot attack due to its condition!" << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->Name << " is now in Gatekeeper mode." << std::endl;
}