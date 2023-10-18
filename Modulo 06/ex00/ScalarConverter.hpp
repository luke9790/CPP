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

		static void	validTypo(std::string);
		static void	detectTypo(std::string);
		static bool detectOverfloa(size_t);

		static void detectInf(std::string);

		static void	charTypo(char* num);
		static void	intTypo(char* num);
		static void	floatTypo(char* num);
		static void	doubleTypo(char* num);
};

#endif