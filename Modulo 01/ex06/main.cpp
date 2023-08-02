/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:09:02 by lmasetti          #+#    #+#             */
/*   Updated: 2023/07/31 15:16:34 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cout << "Usage: harlFilter level\n";
        return (1);
    }

    Harl harl;
    harl.complain(av[1]);

    return (0);
}
