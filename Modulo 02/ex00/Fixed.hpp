#ifndef FIXED_HPP
#define FIXED_HPP
#include <string>
#include <iostream>

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

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif