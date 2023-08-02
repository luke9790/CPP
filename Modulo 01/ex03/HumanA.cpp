/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:07:37 by lmasetti          #+#    #+#             */
/*   Updated: 2023/08/01 12:34:57 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& wpon)
{
    this->name = name;
    arma = &wpon;
}

/*	stessa roba di sopra ma con puntatore invece di reference a puntatore.
HumanA::HumanA(std::string name, Weapon* wpon)
{
    this->name = name;
    arma = wpon;
}
*/

HumanA::~HumanA()
{
    return;
}

void    HumanA::attack()
{
    std::cout << name << " attacks with their " << arma->getType() << std::endl;
    return;
}