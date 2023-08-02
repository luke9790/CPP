/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:07:03 by lmasetti          #+#    #+#             */
/*   Updated: 2023/07/31 15:07:04 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *orda = zombieHorde(5, "Robbie");
    int i = 0;
    while(i < 5)
    {
        orda[i].announce();
        i++;
    }
    delete[] orda;
    return 0;
}