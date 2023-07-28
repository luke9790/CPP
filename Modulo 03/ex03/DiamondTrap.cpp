#include "./DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), Name(ClapTrap::Name + "_clap_name") 
{
	this->HitPoints = FragTrap::HitPoints;
	this->EnergyPoints = ScavTrap::EnergyPoints;
	this->AttackDmg = FragTrap::AttackDmg;
	std::cout << "DiamondTrap default constructor called" << std::endl; 
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap default destructor called for " << this->Name << std::endl; 
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), Name(name + "_clap_name")
{
	this->HitPoints = FragTrap::HitPoints;
	this->EnergyPoints = ScavTrap::EnergyPoints;
	this->AttackDmg = FragTrap::AttackDmg;
	std::cout << "DiamondTrap constructor called, named: " << this->Name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy)
{
	this->HitPoints = copy.HitPoints;
	this->EnergyPoints = copy.EnergyPoints;
	this->AttackDmg = copy.AttackDmg;
	this->Name = copy.Name;
	std::cout << "DiamondTrap copy constructor called for "<< this->Name << std::endl; 
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const &assign)
{
	this->HitPoints = assign.HitPoints;
	this->EnergyPoints = assign.EnergyPoints;
	this->AttackDmg = assign.AttackDmg;
	this->Name = assign.Name;
	std::cout << "DiamondTrap assign operator constructor called" << std::endl;
	return *this;
}

void	DiamondTrap::attack(const std::string& target)
{
	std::cout << "DiamondTrap " << this->Name << " attack using ScavTrap!" << std::endl;
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap use whomai!\n\tis name : " << this->Name << "\n\tClapname: " << ClapTrap::Name << std::endl;
}