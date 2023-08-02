/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:08:45 by lmasetti          #+#    #+#             */
/*   Updated: 2023/07/31 15:17:47 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese";
    std::cout << "-triple-pickle-specialketchup burger.";
    std::cout << "I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money.";
    std::cout << " You didn’t put enough bacon in my burger! If you did,";
    std::cout << " I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free.";
    std::cout << " I’ve been coming for years whereas you started working here";
    std::cout << " since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
    std::cout <<  "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string complains[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    func functs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int i = 0;
    while (i < 4) {
        if (complains[i] == level)
            break;
        i++;
    }
    switch (i)
    {
    case 0:
        while (i < 4)
        {
            (this->*functs[i])();
            i++;
        }
        break;
    case 1:
        while (i < 4)
        {
            (this->*functs[i])();
            i++;
        }
        break;
    case 2:
        while (i < 4)
        {
            (this->*functs[i])();
            i++;
        }
        break;
    case 3:
        while (i < 4)
        {
            (this->*functs[i])();
            i++;
        }
        break; 
    default:
        std::cout << "[ " << "Probably complaining about insignificant problems" << " ]"<< std::endl;
        break;
    }
}