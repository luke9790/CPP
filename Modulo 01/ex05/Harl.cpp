#include "./Harl.hpp"

Harl::Harl()
{
    return;
}

Harl::~Harl()
{
    return;
}

void Harl::debug(void)
{
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese"
    std::cout << "-triple-pickle-specialketchup burger."
    std::cout << "I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "INFO: I cannot believe adding extra bacon costs more money."
    std::cout << " You didn’t put enough bacon in my burger! If you did,"
    std::cout << " I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "WARNING: I think I deserve to have some extra bacon for free.";
    std::cout << "I’ve been coming for years whereas you started working here";
    std::cout << "since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout <<  "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    std::map<std::string, std::function<void()>> complaintMap = {
            { "DEBUG", std::bind(&Harl::debug, this) },
            { "INFO", std::bind(&Harl::info, this) },
            { "WARNING", std::bind(&Harl::warning, this) },
            { "ERROR", std::bind(&Harl::error, this) }
        };

    auto it = complaintMap.find(level);
    if (it != complaintMap.end()) 
        {
        (it->second)(); // Call the appropriate member function using the function pointer
        } 
    else 
        {
        std::cout << "Invalid level: " << level << std::endl;
        }
}
