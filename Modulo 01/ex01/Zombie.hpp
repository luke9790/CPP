#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>
#include <string>


class Zombie
{
private:
    std::string name;

public:
    Zombie(); // Default constructor
    ~Zombie(); // Destructor

    void announce(); // Member function to announce the zombie
    void set_name(std::string name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif