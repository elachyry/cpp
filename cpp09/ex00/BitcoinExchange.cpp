/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:20:44 by melachyr          #+#    #+#             */
/*   Updated: 2024/10/03 21:22:40 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( void )
{
	loadDatabase();
}

BitcoinExchange::BitcoinExchange(std::string& inputFile) : inputFile(inputFile)
{
	loadDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange::~BitcoinExchange( void ) {}

BitcoinExchange&	BitcoinExchange::operator = (const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->database = other.database;
	}
	return (*this);
}

std::string trim(const std::string& str)
{
	size_t start = 0;
	size_t end = str.length();

	while (start < end && std::isspace(str[start]))
		++start;

	while (end > start && std::isspace(str[end - 1]))
		--end;

	return (str.substr(start, end - start));
}


bool	isValidNumber(const std::string& str)
{
	int dotCount = 0;
	bool lastWasDigit = false;

	for (size_t i = 0; i < str.length(); i++)
	{
		if ((str[i] == '-' || str[i] == '+') && i == 0)
			continue ;
		else if (isdigit(str[i])) 
			lastWasDigit = true;
		else if (str[i] == '.')
		{
			if (!lastWasDigit) return false;
			dotCount++;
			lastWasDigit = false;
		} 
		else
			return false;
	}
	return (lastWasDigit && dotCount <= 1);
}

bool	checkIfNumeric(std::string str)
{
	if (str.empty())
		return (false);
	
	std::string::iterator it = str.begin();
	std::string::iterator ite = str.end();
	
	for (; it != ite; it++)
	{
		if (*it == '+' && it == str.begin())
			continue ;
		if (!std::isdigit(*it))
			return (false);
	}
	return (true);
}

Map	split(const std::string& str, char delimiter)
{
	Map	tokens;
	std::string token;
	std::stringstream ss(str);
	
	std::string	key;
	if (str.find(delimiter) == std::string::npos)
	{
		std::getline(ss, token, delimiter);
		key = token;
		tokens[key] = 0;
		return (tokens);
	}
	std::getline(ss, token, delimiter);
	key = trim(token);
	std::getline(ss, token, delimiter);
	token = trim(token);
	if (token.empty())
		throw std::logic_error(str);
	if (!isValidNumber(token))
		throw std::logic_error(token);
	float	value = std::atof(token.c_str());
	tokens[key] = value;
	return (tokens);
}

void	BitcoinExchange::loadDatabase( void )
{
	std::ifstream infile("data.csv");
	if (!infile)
		throw std::runtime_error("Exception: could not open database file.");
	std::string	line;
	if (!std::getline(infile, line))
		throw std::runtime_error("Exception: Empty database.");
	int i = 0;
	do
	{
		if (i == 0)
		{
			if (trim(line) != "date,exchange_rate")
				throw std::runtime_error("Exception: Invalid database.");
			i++;
			continue ;
		}
		try
		{
			Map	result = split(line, ',');
			Iterator it = result.begin();
			this->database.insert(std::make_pair(it->first, it->second));
		}
		catch (const std::exception& ex)
		{
			std::cout << "Exception: Bad value on database: " << ex.what() << std::endl;
		}
	} while (std::getline(infile, line));
	infile.close();
}

bool	isValidDate(std::string date)
{
	std::string tokens[3];
	std::string token;
	std::stringstream ss(date);
	char delimeter = '-';

	int	count = 0;
	for (size_t i = 0; i < date.size(); i++)
	{
		if (date.at(i) == delimeter)
			count++;
	}
	if (count != 2)
		return (0);
		
	int i;
	for (i = 0; std::getline(ss, token, delimeter); i++)
	{
		if (i > 2)
			return (false);
		tokens[i] = trim(token);
	}
	if (i < 2)
		return (false);
	if (!checkIfNumeric(tokens[0]) || !checkIfNumeric(tokens[1]) || !checkIfNumeric(tokens[2]))
		return (false);
	double	year = std::atof(tokens[0].c_str());
	double	month = std::atof(tokens[1].c_str());
	double	day = std::atof(tokens[2].c_str());
	if (year <= 0 || year > 2025)
		return (false);
	if (month <= 0 || month > 12)
		return (false);
	if (day <= 0 || day > 31)	
		return (false);
	if ((month == 1 || month == 6 || month == 9 || month == 11) && day == 31)
		return (false);
	if (month == 2)
	{
		if (static_cast<int>(year) % 4 == 0)
		{
			if (day > 29)
				return (false);
		}
		else
		{
			if (day > 28)
				return (false);
		}
	}
	return (true);
}

void	BitcoinExchange::display( void )
{
	std::ifstream infile(this->inputFile.c_str());
	std::string	line;

	if (!infile)
		throw std::runtime_error("Exception: Could not open file.");
	if (!std::getline(infile, line))
		throw std::runtime_error("Exception: Empty file.");
	int i = 0;
	do
	{
		line = trim(line);
		if (i == 0)
		{
			if (line != "date | value")
				throw std::runtime_error("Exception: Invalid file.");
			i++;
			continue ;
		}
		try
		{
			if (line.empty())
				continue ;
			Map	result = split(line, '|');
			Iterator it = result.begin();
			float value = it->second;
			float price = 0;
			Iterator res = this->database.find(it->first);
			if (res == this->database.end())
			{
				Iterator r = this->database.upper_bound(it->first);
				r--;
				if (r != database.end())
					price = r->second;
			}
			else
				price = res->second;
			if (!isValidDate(it->first))
				std::cout << "Error: bad input => " << it->first << std::endl;
			else if (value < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else if (value > 1000)
				std::cout << "Error: too large a number." << std::endl;
			else
				std::cout << it->first << " => " << value << " = " << value * price << std::endl;
			}
		catch(const std::exception& e)
		{
			std::cout << "Error: bad input => " << e.what() << std::endl;
		}
		i++;
	} while (std::getline(infile, line));
	infile.close();
}

