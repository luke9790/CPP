#include "./ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->HitPoints = 10;
	this->EnergyPoints = 10;
	this->AttackDmg = 0;
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << this->Name << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->HitPoints = 10;
	this->EnergyPoints = 10;
	this->AttackDmg = 0;
	this->Name = name;
	std::cout << "ClapTrap constructor called, named: " << this->Name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	this->AttackDmg = copy.AttackDmg;
	this->EnergyPoints = copy.EnergyPoints;
	this->HitPoints = copy.HitPoints;
	this->Name = copy.Name;
	std::cout << "ClapTrap copy constructor called for " << this->Name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& assign)
{
	this->AttackDmg = assign.AttackDmg;
	this->EnergyPoints = assign.EnergyPoints;
	this->HitPoints = assign.HitPoints;
	this->Name = assign.Name;
	std::cout << "Assignation operator called" << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if(this->EnergyPoints > 0 && this->HitPoints > 0)
	{
		this->EnergyPoints--;
		std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->AttackDmg << " points of damage! ";
		std::cout << "Now, ClapTrap " << this->Name << " has " << this->EnergyPoints << " energy points left!" << std::endl;
	}
	else
		std::cout << "Claptrap " << this->Name << " cannot attack due to its condition!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(this->EnergyPoints > 0 && this->HitPoints > 0)
	{
		std::cout << "ClapTrap " << this->Name << ", take damage for " << amount << " hit points! ";
		this->HitPoints -= amount;
		if(this->HitPoints < 0)
			this->HitPoints = 0;
		std::cout << "Now, ClapTrap " << this->Name << " has " << this->HitPoints << " hit points left!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(this->EnergyPoints > 0 && this->HitPoints > 0)
	{
		this->EnergyPoints--;
		this->HitPoints += amount;
		if(this->HitPoints > 10)
			this->HitPoints = 10;
		std::cout << "ClapTrap " << this->Name << ", repairs itself and gets " << amount << " hit points back!" << std::endl;
		std::cout << "Now, ClapTrap " << this->Name << " has " << this->HitPoints << " hit points and " << this->EnergyPoints << " energy points left!" << std::endl;
	}
	else
		std::cout << "Claptrap " << this->Name << " cannot repair itself due to its condition!" << std::endl;
}