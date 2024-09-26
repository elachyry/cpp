/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:20:44 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/19 20:19:20 by melachyr         ###   ########.fr       */
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

	return str.substr(start, end - start);
}

std::map<std::string, float> split(const std::string& str, char delimiter)
{
	std::map<std::string, float> tokens;
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
	float	value = std::atof(token.c_str());
	tokens[key] = value;
	return (tokens);
}

void	BitcoinExchange::loadDatabase( void )
{
	std::ifstream infile("data.csv");
	if (!infile)
	{
		std::cout << "Error: could not open database file." << std::endl;
		exit(1);
	}
	std::string	line;
	for (int i = 0; std::getline(infile, line); i++)
	{
		if (i == 0)
			continue ;
		std::map<std::string, float>	result = split(line, ',');
		std::map<std::string, float>::iterator it = result.begin();
		this->database.insert(std::make_pair(it->first, it->second));
	}
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
		tokens[i] = token;
	}
	if (i < 2)
		return (false);
	int	year = std::atoi(tokens[0].c_str());
	int	month = std::atoi(tokens[1].c_str());
	int	day = std::atoi(tokens[2].c_str());
	if (year <= 0)
		return (false);
	if (month <= 0 || month > 12)
		return (false);
	if (day <= 0 || day > 31)
		return (false);
	return (true);
}

void	BitcoinExchange::display( void )
{
	typedef std::multimap<std::string, float>::iterator iterator; 
	
	std::ifstream infile(this->inputFile.c_str());
	
	if (!infile)
	{
		std::cout << "Error: could not open file." << std::endl;
		exit(1);
	}
	std::string	line;
	for (int i = 0; std::getline(infile, line); i++)
	{
		if (i == 0)
			continue ;
		std::map<std::string, float>	result = split(line, '|');
		std::map<std::string, float>::iterator it = result.begin();
		int j = 0;
		for (iterator db = this->database.begin(); db != this->database.end(); db++, j++)
		{
			float value = it->second;
			float price = 0;
			if (it->first <= db->first)
			{
				std::map<std::string, float>::iterator db2 = db;
				if (it->first < db->first && j)
					db--; 
				price = db->second;
				if (!isValidDate(it->first))
					std::cout << "Error: bad input => " << it->first << std::endl;
				else if (value < 0)
					std::cout << "Error: not a positive number." << std::endl;
				else if (value > 1000)
					std::cout << "Error: too large a number." << std::endl;
				else
					std::cout << it->first << " => " << value << " = " << value * price << std::endl;
				db = db2;
				break;
			}
		}
	}
	infile.close();
}

