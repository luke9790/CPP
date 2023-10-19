/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:50:16 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/19 15:55:40 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./iter.hpp"

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    // Using iter with intArray and printElement
    std::cout << "Int Array: ";
    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    // Using iter with doubleArray and printElement
    std::cout << "Double Array: ";
    iter(doubleArray, 5, printElement<double>);
    std::cout << std::endl;

    return 0;
}
