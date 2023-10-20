/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:25:17 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/20 10:41:08 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./easyfind.hpp"

int main()
{
    // Test with a vector
    std::vector<int> intVector;
    intVector.push_back(1);
    intVector.push_back(2);
    intVector.push_back(3);
    intVector.push_back(4);
    intVector.push_back(5);

	std::cout << "Vector of ints = (1,2,3,4,5) " << std::endl;
    try
	{
		std::cout << "Let's try to find the number 3" << std::endl;
        std::vector<int>::iterator result = easyfind(intVector, 3);
        std::cout << "Found at index: " << std::distance(intVector.begin(), result) << std::endl;
    }
	catch (const std::runtime_error& e)
	{
        std::cerr << "Error: " << e.what() << std::endl;
    }
    try
	{
		std::cout << "Let's try to find the number 6" << std::endl;
        easyfind(intVector, 6);  // Value not in the container
    }
	catch (const std::runtime_error& e)
	{
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test with a list
    std::list<int> intList;
    intList.push_back(10);
    intList.push_back(20);
    intList.push_back(30);
    intList.push_back(40);
    intList.push_back(50);
	std::cout << "List of ints = (10,20,30,40,50) " << std::endl;
    try
	{
		std::cout << "Let's try to find the number 20" << std::endl;
        std::list<int>::iterator result = easyfind(intList, 20);
        std::cout << "Found at index: " << std::distance(intList.begin(), result) << std::endl;
    }
	catch (const std::runtime_error& e)
	{
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try
	{
		std::cout << "Let's try to find the number 25" << std::endl;
        easyfind(intList, 25);  // Value not in the container
    }
	catch (const std::runtime_error& e)
	{
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
