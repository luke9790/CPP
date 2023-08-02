/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:07:17 by lmasetti          #+#    #+#             */
/*   Updated: 2023/07/31 15:07:18 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie* Horde = new Zombie[N];
    int i = 0;
    while(i < N)
    {
        Horde[i].set_name(name);
        i++;
    }
    return(Horde);
}