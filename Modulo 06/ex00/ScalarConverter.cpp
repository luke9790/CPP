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

void ScalarConverter::convert (std::string num) 
{
    std::stringstream oss;
    std::string str;

	precision(num);
	detectInf(num); 
	validTypo(num);
	detectTypo(num);

	if (detectOverfloa(0) != true) 
	{
		if (_char < 32 && _char != 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << _char << "'" << std::endl;
	}

	if (detectOverfloa(1) != true)
		std::cout << "int: " << _int << std::endl;

	oss << _float;
	str = oss.str( );
	if (detectOverfloa(2) != true) 
	{
		if (!std::abs(_float - round(_float)) && str.find("+") == std::string::npos)
			std::cout << "float: " << _float << ".0f" << std::endl;
		else
			std::cout << "float: " << std::setprecision(_precision) << _float << "f" << std::endl;
	}

	oss << _double;
	str = oss.str( );
	if (detectOverfloa(3) != true)
	{
		if (!std::abs(_double - round(_double)) && str.find("+") == std::string::npos)
			std::cout << "double: " << _double << ".0" << std::endl;
		else
			std::cout << "double: " << std::setprecision(_precision) << _double << std::endl;
	}
}

void ScalarConverter::precision(std::string num) 
{
	if (num.find('.') != std::string::npos && num.find('f') != std::string::npos)
			_precision = num.size() - num.find('.') - 2;
	else if (num.find('.') != std::string::npos)
			_precision = num.size() - num.find('.') - 1;
	if (_precision < 1)
		_precision = 1;
}

bool ScalarConverter::detectOverfloa(size_t i) 
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

void ScalarConverter::detectInf(std::string num)
 {
	if (num == "-inff" || num == "-inf")
	{
		std::cout << "char: impossible"<< std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		exit(EXIT_SUCCESS);
	}
	if (num == "+inff" || num == "+inf")
	{
		std::cout << "char: impossible"<< std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		exit(EXIT_SUCCESS);
	}
	if (num == "nanf" || num == "nan")
	{
		std::cout << "char: impossible"<< std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		exit(EXIT_SUCCESS);
	}
	return ;
}

void	 ScalarConverter::validTypo(std::string num) 
{
	size_t	n_char;
	size_t	shift;
	size_t	n_dot;

	shift = 0;
	n_dot = 0;
	if (num.length( ) == 1)
		return ;
	if (num.find("f") != std::string::npos && num.at(num.length( ) - 1) == 'f')
		shift++;
	n_char = 0;
	for (unsigned long i = 0; i != num.length( ) - shift; i++) {
		if (i ==0 && (num.at(i) == '+' || num.at(i) == '-'))
			;
		else if (num.at(i) == '.')
			n_dot++;
		else if (!isdigit(num.at(i)))
			n_char++;
	}
	if (n_char == 0 && n_dot < 2)
		return ;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
	exit(EXIT_FAILURE);
}

void ScalarConverter::detectTypo(std::string num)
 {
	if (num.length( ) == 1 && !std::isdigit(num.at(0)))
		return (charTypo(const_cast<char*>(num.c_str( ))));
	if (num.find("f") != std::string::npos && num.at(num.length( ) - 1) == 'f')
		return (floatTypo(const_cast<char*>(num.c_str( ))));
	if (num.find(".") != std::string::npos)
		return (doubleTypo(const_cast<char*>(num.c_str( ))));
	return (intTypo(const_cast<char*>(num.c_str( ))));
}


void ScalarConverter::floatTypo(char* num) 
{
	_temp = strtoll(num, NULL, 10);

	_float = atof(num);
	_char = static_cast<char>(_float);
	_int = static_cast<int>(_float);
	_double = static_cast<double>(_float);

	if(_temp != _float)
		ScalarConverter::doubleTypo(num);
}

void ScalarConverter::doubleTypo(char* num) 
{
	_temp = strtoll(num, NULL, 10);

	_double = atof(num);
	_char = static_cast<char>(_double);
	_int = static_cast<int>(_double);
	_float = static_cast<float>(_double);

}

void ScalarConverter::charTypo(char* num)
{

	_char = num[0];
	_int = static_cast<int>(_char);
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);

	_temp = _int;
}

void ScalarConverter::intTypo(char* num)
{
	_temp = strtoll(num, NULL, 10);

	_int = atoi(num);
	_char = static_cast<char>(_int);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);

	if(_temp != _int)
		ScalarConverter::floatTypo(num);
}
