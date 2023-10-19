/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:18:33 by lmasetti          #+#    #+#             */
/*   Updated: 2023/10/19 11:27:07 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "iostream"
# include "iomanip"
# include "cstdlib"
# include "climits"
# include "cfloat"
# include "string"
# include "sstream"
# include "string"
# include "cmath"

class ScalarConverter
{
	private:

		static char				_char;
		static int				_int;
		static float			_float;
		static double			_double;
		static long long int	_temp;
		static int				_precision;

		ScalarConverter(void);
		~ScalarConverter(void);
		ScalarConverter(ScalarConverter&);
		ScalarConverter operator=(ScalarConverter&);
	public:

		static void precision(std::string);
		
		static void convert(std::string);

		static void	validInput(std::string);
		static void	detectTypeOfInput(std::string);
		static bool changeOverfloated(size_t);

		static void limitcases(std::string);

		static void	isAChar(char* num);
		static void	isAInt(char* num);
		static void	IsAFloat(char* num);
		static void	isADouble(char* num);
};

#endif