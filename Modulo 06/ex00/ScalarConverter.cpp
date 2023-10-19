/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:18:23 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/19 11:27:07 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char			ScalarConverter::_char;
int				ScalarConverter::_int;
float			ScalarConverter::_float;
double			ScalarConverter::_double;
long long int	ScalarConverter::_temp;
int				ScalarConverter::_precision;

ScalarConverter::ScalarConverter(void) { };

ScalarConverter::ScalarConverter(ScalarConverter& raw) 
{
	(void)raw;
}

ScalarConverter::~ScalarConverter(void) { };

ScalarConverter ScalarConverter::operator=(ScalarConverter& raw) 
{
	(void)raw;
	return (*this);
}

void ScalarConverter::convert (std::string input) 
{
    std::stringstream oss;
    std::string str;

	precision(input);
	limitcases(input); 
	validInput(input);
	detectTypeOfInput(input);

	if (changeOverfloated(0) != true) 
	{
		if (_char < 32 && _char != 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << _char << "'" << std::endl;
	}

	if (changeOverfloated(1) != true)
		std::cout << "int: " << _int << std::endl;

	oss << _float;
	str = oss.str( );
	if (changeOverfloated(2) != true) 
	{
		if (!std::abs(_float - round(_float)) && str.find("+") == std::string::npos)
			std::cout << "float: " << _float << ".0f" << std::endl;
		else
			std::cout << "float: " << std::setprecision(_precision) << _float << "f" << std::endl;
	}

	oss << _double;
	str = oss.str( );
	if (changeOverfloated(3) != true)
	{
		if (!std::abs(_double - round(_double)) && str.find("+") == std::string::npos)
			std::cout << "double: " << _double << ".0" << std::endl;
		else
			std::cout << "double: " << std::setprecision(_precision) << _double << std::endl;
	}
}

void ScalarConverter::precision(std::string input) 
{
	if (input.find('.') != std::string::npos && input.find('f') != std::string::npos)
			_precision = input.size() - input.find('.') - 2;
	else if (input.find('.') != std::string::npos)
			_precision = input.size() - input.find('.') - 1;
	if (_precision < 1)
		_precision = 1;
}

bool ScalarConverter::changeOverfloated(size_t i) 
{
	switch (i)
	{
		case 0:
			if (_temp != _char)
				return (std::cout << "char: overflow"<< std::endl, true);
			break ;
		case 1:
			if (_temp != _int)
				return (std::cout << "int: overflow" << std::endl, true);
			break ;
		case 2:
			if (std::isinf(_float))
				return (std::cout << "float: overflow" << std::endl, true);
			break ;
		case 3:
			if (std::isinf(_double))
				return (std::cout << "double: overflow" << std::endl, true);
			break ;
	}
	return(false);
}

void ScalarConverter::limitcases(std::string input)
 {
	if (input == "-inff" || input == "-inf")
	{
		std::cout << "char: impossible"<< std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		exit(0);
	}
	if (input == "+inff" || input == "+inf")
	{
		std::cout << "char: impossible"<< std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		exit(0);
	}
	if (input == "nanf" || input == "nan")
	{
		std::cout << "char: impossible"<< std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		exit(0);
	}
	return ;
}

void	 ScalarConverter::validInput(std::string input) 
{
	size_t	number_of_chars;
	size_t	isthereanf;
	size_t	number_of_dots;

	isthereanf = 0;
	number_of_dots = 0;
	if (input.length( ) == 1)
		return ;
	if (input.find("f") != std::string::npos && input.at(input.length( ) - 1) == 'f')
		isthereanf++;
	number_of_chars = 0;
	for (unsigned long i = 0; i != input.length( ) - isthereanf; i++)
	{
		if (i == 0 && (input.at(i) == '+' || input.at(i) == '-'))
			;
		else if (input.at(i) == '.')
			number_of_dots++;
		else if (!isdigit(input.at(i)))
			number_of_chars++;
	}
	if (number_of_chars == 0 && number_of_dots < 2)
		return ;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
	exit(1);
}

void ScalarConverter::detectTypeOfInput(std::string input)
 {
	// len 1, non e' un digit == e' un char
	if (input.length( ) == 1 && !std::isdigit(input.at(0)))
		return (isAChar(const_cast<char*>(input.c_str( ))));
	// se c'e' la f e' un float
	if (input.find("f") != std::string::npos && input.at(input.length( ) - 1) == 'f')
		return (IsAFloat(const_cast<char*>(input.c_str( ))));
	// se c'e' un punto e' un double
	if (input.find(".") != std::string::npos)
		return (isADouble(const_cast<char*>(input.c_str( ))));
	// se non e' nessuno dei precedenti e' un int
	return (isAInt(const_cast<char*>(input.c_str( ))));
}

void ScalarConverter::IsAFloat(char* input) 
{
	_temp = strtoll(input, NULL, 10);

	_float = atof(input);
	_char = static_cast<char>(_float);
	_int = static_cast<int>(_float);
	_double = static_cast<double>(_float);

	if(_temp != _float)
		ScalarConverter::isADouble(input);
}

void ScalarConverter::isADouble(char* input) 
{
	_temp = strtoll(input, NULL, 10);

	_double = atof(input);
	_char = static_cast<char>(_double);
	_int = static_cast<int>(_double);
	_float = static_cast<float>(_double);

}

void ScalarConverter::isAChar(char* input)
{

	_char = input[0];
	_int = static_cast<int>(_char);
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);

	_temp = _int;
}

void ScalarConverter::isAInt(char* input)
{
	// convertiamo in un long long int
	_temp = strtoll(input, NULL, 10);

	_int = atoi(input);
	_char = static_cast<char>(_int);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);

	// se non sono uguali e' in overflow
	if(_temp != _int)
		ScalarConverter::IsAFloat(input);
}
