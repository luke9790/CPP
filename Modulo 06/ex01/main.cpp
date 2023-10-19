/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:36:35 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/19 11:36:37 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int	main(void)
{
	Data*		data;
	uintptr_t	uinptr;

	data = new Data;
	uinptr = Serializer::serialize(data);
	std::cout << "Data pointer is: " << data << std::endl;
	std::cout << "Uinptr number is: " << uinptr << std::endl;
	std::cout << "Deserialize point back to: " << Serializer::deserialize(uinptr) << std::endl;
	delete data;
	return (0);
}