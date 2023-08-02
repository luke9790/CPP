#include "./Fixed.hpp"

int main( void )
{
	Fixed a;					 // stampa default constructor
	Fixed const b( 10 );		// stampa INT constructor
	Fixed const c( 42.42f );	// stampa FLOAT constructor
	Fixed const d( b );			// stampa COPY constructor
	a = Fixed( 1234.4321f );	// stampa FLOAT, COPY ASSIGN, DISTRUGGE IL FLOAT FIXED (oggetto temporaneo)

	// la presenza del suffisso "f" alla fine del valore "1234.4321" 
	// indica che si tratta di un valore di tipo float. Senza il suffisso "f",
	// il valore sarebbe interpretato come un valore di tipo double.
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}