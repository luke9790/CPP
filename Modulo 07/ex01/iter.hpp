/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:50:20 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/19 15:56:38 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename Func>
void iter(T* arr, size_t lenght, Func function)
{
    for (size_t i = 0; i <  lenght; ++i)
    {
        function(arr[i]);
    }
}

// Example function to use with iter
template <typename T>
void printElement(const T& element)
{
    std::cout << element << " ";
}

#endif