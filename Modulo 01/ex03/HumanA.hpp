/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:07:40 by lmasetti          #+#    #+#             */
/*   Updated: 2023/07/31 15:07:41 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "./Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon* arma;

    public:
        HumanA(std::string name, Weapon& wpon);
        ~HumanA();

    void    attack();
};

#endif