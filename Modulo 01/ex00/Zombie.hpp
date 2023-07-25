#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <string>


class Zombie
{
private:
	std::string name;

public:
	Zombie();
	Zombie(const std::string& name);
	~Zombie();

	void announce() const;
	static Zombie* newZombie(std::string name);
	static void randomChump(std::string name);
};

#endif