/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:25:17 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/27 15:59:36 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"

int main(int ac, char **av)
{
    if(ac < 2)
    {
        std::cout << "Error: invalid number of arg." << std::endl;
        return 1;
    }
    try
    {
        PmergeMe::ParsArgs(av);
        PmergeMe::Time( );
    } 
    catch (std::exception& e) 
    {
        std::cout << e.what( ) << std::endl;
        return (1);
    }
    return (0);
}
