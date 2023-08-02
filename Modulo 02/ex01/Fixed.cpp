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
	this->fixed_point = roundf(floatnum * (1 << num_bits)); // sposta il bit 1 a sinistra di num_bits posizioni. Questo è il fattore di scala per convertire il valore in una rappresentazione a precisione fissa.
}

float Fixed::toFloat() const
{
    return static_cast<float>(fixed_point) / (1 << num_bits); // dobbiamo dividere fixed_point per 2^num_bits. Questo è perché fixed_point ha il punto decimale spostato di num_bits posizioni a sinistra rispetto a un intero normale
}

int Fixed::toInt() const
{
    return fixed_point >> num_bits; // per convertire basta spostare il fixed point a destra per n_bits bits.
}

std::ostream& operator<<(std::ostream& outputstream, const Fixed& fixed)
{
    outputstream << fixed.toFloat();
    return outputstream;
}