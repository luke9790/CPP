/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:25:17 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/26 12:58:51 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main()
{
    Span spa(5);
    spa.addNumber(6);
    spa.addNumber(3);
    spa.addNumber(17);
    spa.addNumber(9);
    spa.addNumber(11);

    try 
	{
        std::cout << "Shortest Span: " << spa.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << spa.longestSpan() << std::endl;
    } 
	catch (const std::exception& e) 
	{
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::vector<int> moreNumbers;
    moreNumbers.push_back(1);
    moreNumbers.push_back(5);
    moreNumbers.push_back(20);

    try 
	{
        spa.addNumbers(moreNumbers);
        std::cout << "Shortest Span after adding more numbers: " << spa.shortestSpan() << std::endl;
        std::cout << "Longest Span after adding more numbers: " << spa.longestSpan() << std::endl;
    }
	catch (const std::exception& e)
	{
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
