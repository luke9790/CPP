/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:18:33 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/24 10:56:11 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cfloat>
#include <cerrno>
#include <stdlib.h>
#include <iomanip>
#include <sstream>

class ScalarConverter
{
private:

	ScalarConverter();
	ScalarConverter(const ScalarConverter& src);
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter& assign);

	static char _char;
	static int _int;
	static float _float;
	static double _double;
	static bool _err;
	static bool _inf;

public:
	static void convert(const std::string& src);
	static void FindType(const std::string& input);
	static void charConv(const std::string& src);
	static void intConv(const std::string& src);
	static void floatConv(const std::string& src);
	static void doubleConv(const std::string& src);
	static void PrintConv(const std::string& src);
};

#endif