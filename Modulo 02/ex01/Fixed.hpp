/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:46:21 by lmasetti          #+#    #+#             */
/*   Updated: 2023/08/30 11:46:22 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int	fixed_point;
	static const int num_bits = 8;
public:
	Fixed();								// default
	Fixed(const Fixed& copy);				// copy constructor
	Fixed& operator=(const Fixed& assign);	// copy assignment operator overload
	~Fixed();								// destructor

	Fixed(const int intnum);
	Fixed(const float floatnum);

	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float toFloat( void ) const;
	int toInt( void ) const;
	friend std::ostream& operator<<(std::ostream& outputstream, const Fixed& fixed);

};

#endif