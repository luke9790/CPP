/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:50:16 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/25 15:15:51 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Array.hpp"

int main()
{
    try {
        // empty array 
        Array<int> arr1;
        std::cout << "arr1 size: " << arr1.size() << std::endl;

        // array with 5 elements
        Array<int> arr2(5);
        std::cout << "arr2 size: " << arr2.size() << std::endl;

        arr2[0] = 1;
        arr2[1] = 2;
        arr2[2] = 3;
        arr2[3] = 4;
        arr2[4] = 5;

        // Copy the array
        Array<int> arr3(arr2);

        // Display the contents of arr3
        std::cout << "arr3 size: " << arr3.size() << std::endl;
        for (int i = 0; i < arr3.size(); i++) 
		{
            std::cout << "arr3[" << i << "] = " << arr3[i] << std::endl;
        }

        // Modify arr2 and make sure arr3 remains unaffected
        arr2[0] = 100;

        std::cout << "After modifying arr2:" << std::endl;
        std::cout << "arr2[0] = " << arr2[0] << std::endl;
        std::cout << "arr3[0] = " << arr3[0] << std::endl;

        // Test out of bounds access
        std::cout << "Trying to access an out of bounds element:" << std::endl;
        arr3[5] = 42; 

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
	try{
		Array<int> arr3(5);
		std::cout << "Trying to access a negative index:" << std::endl;
        arr3[-1] = 42; 

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
