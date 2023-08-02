/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:07:44 by lmasetti          #+#    #+#             */
/*   Updated: 2023/07/31 15:07:45 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
}

HumanB::~HumanB()
{
    return;
}

void    HumanB::attack()
{
    std::cout << name << " attacks with their " << arma->getType() << std::endl;
    return;
}

void    HumanB::setWeapon(Weapon& arma)
{
    this->arma = &arma;
}