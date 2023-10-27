/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:49:15 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/27 15:51:02 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<int>			RPN::_vStack;

const std::string inputvalidi("1234567890/*-+ ");
const std::string cifre("1234567890");
const std::string operazioni("/*-+");

// template <typename T>
// void printStack(const std::stack<T>& s)
// {
//     std::stack<T> tempStack = s;

//     while (!tempStack.empty())
// 	{
//         std::cout << tempStack.top() << " ";
//         tempStack.pop();
//     }
//     std::cout << std::endl;
// }

void RPN::ParsArgs(const char *av)
{
	std::string str_arg(av);
	for (size_t i = 0; i < str_arg.size( ); i++)
		if (inputvalidi.find(str_arg.at(i))== std::string::npos)
			throw std::invalid_argument("Error.");
}

void RPN::Operations(std::string& op)
{
	int	first;
	int second;

	if (_vStack.size( ) < 2)
    	throw std::invalid_argument("Error: Not enough operands for operator!");
	first = _vStack.top( );
	_vStack.pop( );
	second = _vStack.top( );
	_vStack.pop( );

	if (op == "+")
		_vStack.push(second + first);
	if (op == "-")
		_vStack.push(second - first);
	if (op == "*")
		_vStack.push(second * first);
	if (op == "/") {
		if (first == 0)
			throw std::invalid_argument("Error: Can't divide by 0!");
	_vStack.push(second / first);
	}
}

void RPN::Fill(const char *c_arg)
{
	std::istringstream	ss(c_arg);
	std::string			elem;

	do {
		std::getline(ss, elem, ' ');
		if (elem.empty( ))
			goto bb;
		if ((cifre.find(elem) == std::string::npos && operazioni.find(elem) == std::string::npos))
			throw std::invalid_argument("Error.");
		if(cifre.find(elem) != std::string::npos)
			_vStack.push(std::atoi(elem.c_str( )));
		if(operazioni.find(elem) != std::string::npos)
			RPN::Operations(elem);
		bb:
			;
	} while (!ss.eof( ));
	if (_vStack.size( ) == 1)
		std::cout << _vStack.top( ) << std::endl;
	else
		throw std::invalid_argument("Error.");
}