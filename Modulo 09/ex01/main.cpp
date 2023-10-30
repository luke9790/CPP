/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:46:50 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/30 11:08:08 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char** av)
{
 	if(ac != 2)
    {
        std::cout << "Error: invalid number of arg." << std::endl;
        return 1;
    }
	try
	{
		RPN::Parsing(av[1]);
		RPN::Fill(av[1]);
	} 
	catch (std::exception &e) 
	{
		std::cout << e.what( ) << std::endl;
		return (1);
	}
	return (0);
}