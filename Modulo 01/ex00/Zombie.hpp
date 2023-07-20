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
    Zombie(const std::string& name); // Constructor with name parameter
    ~Zombie(); // Destructor

    void announce() const; // Member function to announce the zombie
    static Zombie* newZombie(std::string name);
    static void randomChump(std::string name);
};

#endif