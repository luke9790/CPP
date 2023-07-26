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
	friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

	    // Overloaded comparison operators
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    // Overloaded arithmetic operators
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // Increment and decrement operators
    Fixed& operator++();     // Pre-increment
    Fixed operator++(int);   // Post-increment
    Fixed& operator--();     // Pre-decrement
    Fixed operator--(int);   // Post-decrement

    // Static member functions for finding minimum and maximum values
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

#endif