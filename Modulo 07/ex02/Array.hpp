/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:50:20 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/19 17:35:27 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template <class T>
class Array
{
private:
	T* _arr;
	int _size;

public:
	Array();
	~Array();
	Array(unsigned int n);
	Array(const Array& src);
	Array& operator=(const Array& src);

	T& operator[](int i) const;
	int size() const;
};

#include "Array.tpp"

#endif