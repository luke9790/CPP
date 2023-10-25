/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:18:23 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/25 11:06:36 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char ScalarConverter::_char;
int ScalarConverter::_int;
float ScalarConverter::_float;
double ScalarConverter::_double;
bool ScalarConverter::_err;
bool ScalarConverter::_inf;

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	*this = src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& assign)
{
	if (this != &assign)
	{
		_char = assign._char;
		_int = assign._int;
		_float = assign._float;
		_double = assign._double;
		_err = assign._err;
		_inf = assign._inf;
	}
	return *this;
}

// usiamo stringstream per convertire l'input in una stringa formata da
// caratteri e proviamo a estrarre con >> sul tipo di dato che aspettiamo.
// se raggiungiamo la fine del file(eof) e non fallisce lo stream, significa
// che il dato combacia con quanto ci aspettiamo.

bool isInt(const std::string& input)
{
    std::stringstream stream(input);
	int i;
    stream >> i;
    return stream.eof() && !stream.fail();
}

bool isFloat(const std::string& input)
{
	std::string trim = input;
	trim.erase(trim.length() - 1);
    std::stringstream stream(trim);
	float f;
    stream >> f;
    return stream.eof() && !stream.fail();
}

bool isDouble(const std::string& input)
{
    std::stringstream stream(input);
	double d;
    stream >> d;
    return stream.eof() && !stream.fail();
}

void ScalarConverter::charConv(const std::string& input)
{
	
	_char = static_cast<char>(input[0]);
	_int = static_cast<int>(_char);
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);
}

/*
errno e' una variabile globale che conserva i codici errori,
se corrisponde a erange significa che nella conversione abbiamo
un overflow.
*/

void ScalarConverter::intConv(const std::string& input)
{

	_int = std::strtol(input.c_str(), 0, 10);
	if (errno == ERANGE){
		_err = true;
		return ;
	}
	_char = static_cast<char>(_int);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
}

void ScalarConverter::floatConv(const std::string& input)
{

	_float = std::strtof(input.c_str(), 0);
	if (errno == ERANGE){
		_err = true;
		return ;
	}
	_char = static_cast<char>(_float);
	_int = static_cast<int>(_float);
	_double = static_cast<double>(_float);
}

void  ScalarConverter::doubleConv(const std::string& input)
{

	_double = std::strtod(input.c_str(), 0);
	if (errno == ERANGE){
		_err = true;
		return ;
	}
	_char = static_cast<char>(_double);
	_int = static_cast<int>(_double);
	_float = static_cast<float>(_double);
}

/*
serve per trovare i numeri dopo la virgola( o meglio il punto),
quindi la parte decimale dell'input. Viene usata ovviamente solo
per i float e i double. Se l'input non ha valori decimali resta a 1.
*/

int precisionFinder(const std::string& input)
{
	size_t pos = 0;
	size_t trim = 1;
	if (input[input.length() - 1] == 'f')
		trim++;
	pos = input.find('.');
	if (pos != input.npos)
		return input.length() - pos - trim;
	return 1;
}

void ScalarConverter::PrintConv(const std::string& input)
{
    std::cout << "Char: ";
    if (isprint(_char) && !_inf && _int > std::numeric_limits<char>::min() && _int < std::numeric_limits<char>::max())
        std::cout << "'" << _char << "'" << std::endl;
    else if (!_err && !_inf && _int > std::numeric_limits<char>::min() && _int < std::numeric_limits<char>::max())
        std::cout << "Non displayable" << std::endl;
    else if (_err || _inf || _int < std::numeric_limits<char>::min() || _int > std::numeric_limits<char>::max())
        std::cout << "impossible" << std::endl;

    std::cout << "Int: ";
    if (!_err && !_inf)
	{
        if (_int > std::numeric_limits<int>::min() && _int < std::numeric_limits<int>::max())
            std::cout << _int << std::endl;
        else
            std::cout << "overflow" << std::endl;
    } 
	else 
        std::cout << "impossible" << std::endl;

    std::cout << "Float: ";
    if (!_err && !_inf) 
	{
        if (_float > -FLT_MAX && _float < FLT_MAX)
            std::cout << std::fixed << std::setprecision(precisionFinder(input)) << _float << "f" << std::endl;
        else
            std::cout << "overflow" << std::endl;
    }
	else if (_inf)
        std::cout << (input[0] == '-' ? "-" : "+") << "inff" << std::endl;
    else
        std::cout << "nanf" << std::endl;

    std::cout << "Double: ";
    if (!_err && !_inf)
	{
        if (_double > -DBL_MAX && _double < DBL_MAX)
            std::cout << std::fixed << std::setprecision(precisionFinder(input)) << _double << std::endl;
        else
            std::cout << "overflow" << std::endl;
    } 
	else if (_inf)
        std::cout << (input[0] == '-' ? "-" : "+") << "inf" << std::endl;
    else
        std::cout << "nan" << std::endl;
}

void ScalarConverter::FindType(const std::string& input){
	
	
	if (input.find("nan") != input.npos)
		_err = true;
	else if (input.find("inf") != input.npos && input.length() <= 5)
		_inf = true;
	if (input.length() == 1 && !isdigit(static_cast<unsigned char>(input[0])))
		charConv(input);
	else if (isInt(input))
		intConv(input);
	else if (input[input.length() - 1] == 'f' && isFloat(input))
		floatConv(input);
	else if (isDouble(input))
		doubleConv(input);
	else
		_err = true;
}

void ScalarConverter::convert(const std::string& input)
{

	_err = false;
	_inf = false;
	FindType(input);
	PrintConv(input);
}