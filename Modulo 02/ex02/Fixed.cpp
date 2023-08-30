/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:46:34 by lmasetti          #+#    #+#             */
/*   Updated: 2023/08/30 11:46:35 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

Fixed::Fixed()
{
	this->fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(const Fixed& copy)
{
	this->fixed_point = copy.fixed_point;
	std::cout << "Copy constructor called" << std::endl;
	return;
}

Fixed& Fixed::operator=(const Fixed& assign)
{
	this->fixed_point = assign.fixed_point;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed_point = raw;
}

Fixed::Fixed(const int intnum)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point = intnum << num_bits;
}

Fixed::Fixed(const float floatnum)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point = roundf(floatnum * (1 << num_bits));
}

float Fixed::toFloat() const
{
    return static_cast<float>(fixed_point) / (1 << num_bits);
}

int Fixed::toInt() const
{
    return fixed_point >> num_bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

// roba nuova

// 6 comparison operators: >, <, >=, <=, == and !=.
bool Fixed::operator>(const Fixed& other) const
{
    return this->fixed_point > other.fixed_point; // fa il confronto e ritorna se vero o falso.
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->fixed_point < other.fixed_point;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->fixed_point >= other.fixed_point;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->fixed_point <= other.fixed_point;
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->fixed_point == other.fixed_point;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->fixed_point != other.fixed_point;
}

// 4 arithmetic operators: +, -, *, and /.

Fixed Fixed::operator+(const Fixed& other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

// The 4 increment/decrement operators

Fixed& Fixed::operator++() // pre
{
    ++this->fixed_point;
    return *this;
}

Fixed Fixed::operator++(int) // post: crea una copia temporanea che viene returnata ma aumenta il valore originale.
{
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() // pre
{
    --this->fixed_point;
    return *this;
}

Fixed Fixed::operator--(int) // post: crea una copia temporanea che viene returnata ma diminuisce il valore originale.
{
    Fixed temp(*this);
    --(*this);
    return temp;
}

//  four public overloaded member functions: min, min(const), max, max(const) 

// OPERATORE TERNARIO: condizione ? espressione_se_vera : espressione_se_falsa;

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;  
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}
