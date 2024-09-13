/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:29:41 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/13 18:30:12 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char	ScalarConverter::charVal;
int		ScalarConverter::intVal = 0;
float	ScalarConverter::floatVal = 0;
double	ScalarConverter::doubleVal = 0;
bool	ScalarConverter::isPrintable = true;
bool	ScalarConverter::check = true;

ScalarConverter::ScalarConverter( void ) {}

ScalarConverter::ScalarConverter(const ScalarConverter& scalarConverter)
{
	*this = scalarConverter;
}

ScalarConverter::~ScalarConverter( void ) {}

ScalarConverter&	ScalarConverter::operator = (const ScalarConverter& scalarConverter)
{
	if (this != &scalarConverter) {}
	return (*this);
}

int isascii(int ch)
{
	return (ch >= 0 && ch < 128);
}

DataType	ScalarConverter::detectInputType(const char* str)
{
	std::string input = str;

	if (input.size() == 1 && !std::isdigit(input.at(0)))
		return (TCHAR);
	if (input == "nan" || input == "nanf")
		return (NAN);
	if (input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff")
		return (INF);
	for(size_t i = 0, count = 0; i < input.size() ; i++)
	{
		if (i == 0)
		{
			if (input[i] == '+' || input[i] == '-')
				continue ;
		}
		if ((input[i] == '.' && i == 0) || (input[i] == '.' && i == input.size() - 1) || (i == input.size() - 2 && input[i] == '.'  && input[input.size() - 1] == 'f'))
			return (NONNUMERIC);
		if (input[i] == '.')
			count++;
		if ((!std::isdigit(input[i]) && input[i] == '.' && count > 1)
			|| (isascii(input[i]) && input[i] != '.' && !std::isdigit(input[i])))
		{
			if (i == input.size() - 1 && input[i] == 'f' && count)
				continue;
			return (NONNUMERIC);
		}
	}
	if (std::atoi(str) < 32 || std::atoi(str) > 126)
		isPrintable = false;
	if (input.find(".") != std::string::npos)
	{
		int 	count = 0;
		bool	flag = false;
		for (size_t j = 0; j < input.size() ; j++)
		{
			if (input[j] == '.')
			{
				j++;
				for (size_t k = j; k < input.size(); k++)
				{
					if (input[k] == '0')
						count++;
					else if (input[k] == 'f')
						flag = true;
					else
						break;
					if (k == input.size() - 1)
						flag = true;
				}
			}
		}
		if (count <= 3 && !flag)
			check = false;
		if (input.find("f") != std::string::npos)
			return (TFLOAT);
		return (TDOUBLE);
	}
	return (TINT);
}

void	ScalarConverter::printValues( DataType error )
{
	switch (error)
	{
		case INF:
		case NAN:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << floatVal << "f" << std::endl;
			std::cout << "double: " << doubleVal << std::endl;
			break;
		case NONNUMERIC:
			std::cout << "Invalid input" << std::endl;
			break;
		default:
		{
			if (intVal < -128 || intVal > 127 || error == OVERFLOW)
				std::cout << "char: Overflow" << std::endl;
			else if (intVal < 32 || intVal > 126)
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: '" << charVal << "'" << std::endl;
			if (doubleVal > std::numeric_limits<int>::max() || doubleVal < std::numeric_limits<int>::min() || error == OVERFLOW)
				std::cout << "int: Overflow" << std::endl;
			else
				std::cout << "int: " << intVal << std::endl;
			if (error == OVERFLOW)
			{
				std::cout << "float: Overflow" << std::endl;
				std::cout << "double: Overflow" << std::endl;
			}
			else
			{
				if (check)
				{
					std::cout << "float: " << floatVal << ".0" << "f" << std::endl;
					std::cout << "double: " << doubleVal << ".0" << std::endl;
				}
				else
				{
					std::cout << "float: " << floatVal << "f" << std::endl;
					std::cout << "double: " << doubleVal << std::endl;
				}
			}
			break;
		}
	}
}

void	ScalarConverter::castFromChar(char c)
{
	charVal = c;
	intVal = static_cast<int> (charVal);
	floatVal = static_cast<float> (charVal);
	doubleVal = static_cast<double> (charVal);
}

void	ScalarConverter::castFromInt(int n)
{
	intVal = n;
	charVal = static_cast<char> (intVal);
	floatVal = static_cast<float> (intVal);
	doubleVal = static_cast<double> (intVal);
}

void	ScalarConverter::castFromFloat(float f)
{
	floatVal = f;
	charVal = static_cast<char> (floatVal);
	intVal = static_cast<int> (floatVal);
	doubleVal = static_cast<double> (floatVal);
}

void	ScalarConverter::castFromDouble(double d)
{
	doubleVal = d;
	charVal = static_cast<char> (doubleVal);
	intVal = static_cast<int> (doubleVal);
	floatVal = static_cast<float> (doubleVal);
}

void	ScalarConverter::handlNonPrintable(int n)
{
	intVal = n;
	floatVal = static_cast<float> (intVal);
	doubleVal = static_cast<double> (intVal);
}

void	ScalarConverter::handlNonNumeric(double n)
{
	doubleVal = n;
	floatVal = static_cast<float> (doubleVal);
}

void	ScalarConverter::convert(const char* str)
{
	DataType type = detectInputType(str);
	switch(type)
	{
		case TCHAR:
			castFromChar(str[0]);
			break;
		case TINT:
			{
				double	n = std::atof(str);
				if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
				{
					type = OVERFLOW;
					break;
				}
				castFromInt(std::atoi(str));
				break;
			}
		case TFLOAT:
			castFromFloat(std::atof(str));
			break;
		case TDOUBLE:
			castFromDouble(std::atof(str));
			break;
		default:
			handlNonNumeric(std::atof(str));
			break;
	}
	printValues(type);
}
