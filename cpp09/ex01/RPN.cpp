/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:30:00 by melachyr          #+#    #+#             */
/*   Updated: 2024/10/03 21:33:52 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( void ) {}

RPN::RPN(std::string expression)
{
	this->expression = expression;
}

RPN::RPN(const RPN& rpn)
{
	*this = rpn;
}

RPN::~RPN( void ) {}

RPN&	RPN::operator = (const RPN& rpn)
{
	if (this != &rpn)
	{
		this->expression = rpn.expression;
	}
	return(*this);
}

std::string* split(const std::string& str, char delimiter, int& size)
{
	std::istringstream tokenStream(str);
	std::string token;
	int count = 0;
	
	while (std::getline(tokenStream, token, delimiter))
	{
		if (!token.empty())
            count++;
	}

	std::string* result = new std::string[count];
	
	tokenStream.clear();
	tokenStream.str(str);

	int index = 0;
	while (std::getline(tokenStream, token, delimiter))
		if (!token.empty())
			result[index++] = token;

	size = count;
	return (result);
}

bool	isOperator(std::string str)
{
	return (str == "+" || str == "-" || str == "*" || str == "/");
}

bool	isNumber(std::string str)
{
	if (str.empty())
		return (false);
	
	std::string::iterator it = str.begin();
	std::string::iterator ite = str.end();
	
	for (; it != ite; it++)
	{
		if ((*it == '+' || *it == '-') && it == str.begin())
			continue ;
		if (!std::isdigit(*it))
			return (false);
	}
	return (true);
}

float	getResult(float num1, float num2, char o)
{
	float result = 0;
	switch (o)
	{
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '*':
			result = num1 * num2;
			break;
		case '/':
			result = num1 / num2;
			break;
	}
	return (result);
}

float	RPN::process( void )
{
	int	size;
	std::string*	splited = split(this->expression, ' ', size);
	if (!isOperator(splited[size - 1]))
	{
		delete[] splited;
		throw std::runtime_error("Error");
	}
	for (int i = 0; i < size; i++)
	{
		if (isOperator(splited[i]))
		{
			if (expStack.size() < 2)
			{
				delete[] splited;
				throw std::runtime_error("Error");
			}
			float num1 = expStack.top();
			expStack.pop();
			float num2 = expStack.top();
			expStack.pop();
			expStack.push(getResult(num2, num1, splited[i].at(0)));
		}
		else if (isNumber(splited[i]))
		{
			float	nbr = std::atof(splited[i].c_str());
			if (nbr >= 10)
			{
				delete[] splited;
				throw std::runtime_error("Error");
			}
			expStack.push(nbr);
		}
		else
		{
			delete[] splited;
			throw std::runtime_error("Error");
		}
	}
	delete[] splited;
	if (expStack.size() > 2)
		throw std::runtime_error("Error");
	return (expStack.top());
}
