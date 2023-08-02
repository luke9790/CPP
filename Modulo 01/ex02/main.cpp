/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:07:29 by lmasetti          #+#    #+#             */
/*   Updated: 2023/07/31 15:07:29 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string ciao = "HI THIS IS BRAIN";
    std::string *stringPTR = &ciao;
    std::string& stringREF = ciao;

    std::cout << "The memory address of the string variable = " << &ciao << std::endl ;
    std::cout << "The memory address held by stringPTR      = " << stringPTR << std::endl ;
    std::cout << "The memory address held by stringREF      = " << &stringREF << std::endl ;

    std::cout << "The value of the string variable  = " << ciao << std::endl ;
    std::cout << "The value pointed to by stringPTR = " << *stringPTR << std::endl ;
    std::cout << "The value pointed to by stringREF = " << stringREF << std::endl ;
}