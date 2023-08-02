/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:07:48 by lmasetti          #+#    #+#             */
/*   Updated: 2023/07/31 15:07:48 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "./Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon* arma;

    public:
        HumanB(std::string name);
        ~HumanB();

    void    attack();
    void    setWeapon(Weapon& arma);
};

#endif