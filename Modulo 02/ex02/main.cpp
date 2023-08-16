#include "./Fixed.hpp"

int main( void )
{
	Fixed a;

	// prima fixed 2 (int) poi float, si esegue il calcolo ed essendo float
	// si crea un nuovo float. I due fixed nell'espressione vengono distrutti.
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;

	// il valore di a non viene incrementato di 1, ma di 1/256,
	// che è approssimativamente uguale a 0.00390625.
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}