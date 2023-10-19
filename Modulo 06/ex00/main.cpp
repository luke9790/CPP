/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:18:03 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/19 11:18:44 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int ac, char** av)
{
	if (ac != 2)
    {
        std::cout << "Invalid number of argument" << std::endl;
        return (1);
    }

	std::string		input(av[1]);
    ScalarConverter::convert(input);
    return (0);
}