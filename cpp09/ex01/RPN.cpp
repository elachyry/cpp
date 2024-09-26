/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:30:00 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/19 21:08:18 by melachyr         ###   ########.fr       */
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
		// std::cout << "token " << token << std::endl;
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
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str.at(i)))
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
	(void) splited;
	for (int i = 0; i < size; i++)
	{
		// std::cout << splited[i] << std::endl;
		if (isOperator(splited[i]))
		{
			float num1 = expStack.top();
			expStack.pop();
			float num2 = expStack.top();
			expStack.pop();
			expStack.push(getResult(num2, num1, splited[i].at(0)));
			// std::cout << expStack.top() << std::endl;
		}
		else if (isNumber(splited[i]))
			expStack.push(std::atof(splited[i].c_str()));
		else
		{
			std::cout << "Error" << std::endl;
			delete[] splited;
			exit(1);
		}
	}
	delete[] splited;
	return (expStack.top());
}
