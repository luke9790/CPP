/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:37:15 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/25 11:32:01 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base*	generate(void)
{
	int	casuale = rand( ) % 3;
	switch (casuale)
	{
		case (0):
		{
			std::cout << "Il puntatore generato e' della classe A " << std::endl;
			return new A;
		}
		case (1):
		{
			std::cout << "Il puntatore generato e' della classe B " << std::endl;
			return new B;
		}
		case(2):
		{
			std::cout << "Il puntatore generato e' della classe C " << std::endl;
			return new C;
		}
		default:
			break;
	}
	return (NULL);
}

/*
dynamic_cast is an operator used for safe type casting during runtime. 
It primarily works with polymorphic classes. The primary purpose of dynamic_cast
is to ensure that a downcast (from a base class pointer/reference to a
derived class pointer/reference) is valid and safe.
*/

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "Il puntatore e' della classe A" << std::endl;
		return ;
	}
	if (dynamic_cast<B*>(p))
	{
		std::cout << "Il puntatore e' della classe B" << std::endl;
		return ;
	}
	if (dynamic_cast<C*>(p))
	{
		std::cout << "Il puntatore e' della classe C" << std::endl;
		return ;
	}
	std::cout << "Impossibile identificare il puntatore" << std::endl;
}

/*
we are checking the type of the class by using a reference to a pointer of types A, B, or C, 
and then you use dynamic_cast to validate if the reference can be cast to the specified derived class type. 
If the cast succeeds, it means that the object referred to by p is an instance of that derived class. 
If the cast fails, it means that p does not refer to an instance of the specified derived class type.
*/

void	identify(Base& p)
{
	try
	{
		A	&ptr = dynamic_cast<A&>(p);
		(void)ptr;
		std::cout << "Riferimento alla classe A" << std::endl;
	}
	catch (std::exception &e) { };
	try
	{
		B	&ptr = dynamic_cast<B&>(p);
		(void)ptr;
		std::cout << "Riferimento alla classe B" << std::endl;
	}
	catch (std::exception &e) { };
	try
	{
		C	&ptr = dynamic_cast<C&>(p);
		(void)ptr;
		std::cout << "Riferimento alla classe C" << std::endl;
	}
	catch (std::exception &e) { };
}

int main()
{
	for(int i = 1; i < 10; i++)
	{
		Base* rand = generate();
		identify(rand);
		identify(*rand);
		std::cout << "..." << std::endl;
		delete rand;
	}
}