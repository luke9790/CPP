/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:36:35 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/25 11:15:41 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int	main(void)
{
	Data*		data;
	uintptr_t	uinptr; // It's an unsigned integer type that is garanteed to store a pointer

	/*
	The uintptr_t type is used as an intermediary representation for the pointer, 
	allowing it to be easily stored or transmitted as an integer value and later reconstructed as a valid pointer.
	*/

	data = new Data;
	uinptr = Serializer::serialize(data);
	std::cout << "Data pointer is: " << data << std::endl;
	std::cout << "Uinptr number is: " << uinptr << std::endl;
	std::cout << "Deserialize point back to: " << Serializer::deserialize(uinptr) << std::endl;
	delete data;
	return (0);
}