/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:37:15 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/19 13:06:12 by lmasetti         ###   ########.fr       */
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
	Base* rand = generate();
	identify(rand);
	identify(*rand);
	std::cout << "..." << std::endl;
	for(int i = 1; i < 10; i++)
	{
		rand = generate();
		identify(rand);
		identify(*rand);
		std::cout << "..." << std::endl;
	}
	delete rand;
}