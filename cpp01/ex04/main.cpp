/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:18:42 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/27 15:12:44 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	copyAllFile(std::ifstream& inFile, std::ofstream& outFile)
{
	std::string	line;
	
	while (std::getline(inFile, line))
	{
		outFile << line;
		if (!inFile.eof())
			outFile << std::endl;
	}
}

int	getTotalS1InLine(std::string line, std::string s1)
{
	size_t		s1Position;
	int		count = 0;
	
	while (line.length() > 0)
	{
		s1Position = line.find(s1);
		if (s1Position != std::string::npos)
		{	
			line = line.substr(s1.length() + s1Position);
			count++;
		}
		else
			break ;
	}
	return (count);
}

void	replaceS1WithS2(std::ifstream& inFile, std::ofstream& outFile, \
	std::string s1, std::string s2, std::string line)
{
	int			copied = 0;
	size_t		s1Position;
	int			totalLine = 0;
	int			s1Count = getTotalS1InLine(line, s1);
	if (line.find(s1) != std::string::npos)
		totalLine = line.length() - (s1.length() * s1Count) + (s2.length() * s1Count);
	else
		totalLine = line.length();
	while (line.length() > 0 && copied < totalLine)
	{
		int j = 0;
		s1Position = line.find(s1);
		if (s1Position != std::string::npos)
		{	
			while (j < (int)s1Position)
			{
				outFile << line[j];
				j++;
				copied++;
			}
			for (int k = 0; k < (int)s2.length(); k++)
			{
				outFile << s2[k];
				copied++;
			}
			line = line.substr(s1.length() + j);
		}
		else
		{
			while (j < (int)line.length())
			{
				outFile << line[j];
				copied++;
				j++;
			}
		}
	}
	if (!inFile.eof())
		outFile << std::endl;
}

bool	replaceInFile(std::string filename, std::string s1, std::string s2)
{
	std::string	extention = ".replace";
	std::string	outfile =  filename + extention;
	std::string	line;

	std::ifstream inFile(filename.c_str());
	if (!inFile)
	{
		std::cerr << "Cannot open the file!";
		return (true);
	}
	std::ofstream replaceFile(outfile.c_str());
	if (!replaceFile)
	{
		std::cerr << "Cannot create the out file!" << s2;
		return (true);
	}
	if (s1.empty() || s2.empty())
	{
		copyAllFile(inFile, replaceFile);
		return (false);
	}
	while (std::getline(inFile, line))
		replaceS1WithS2(inFile, replaceFile, s1, s2, line);
	return (false);
}

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string	filename = argv[1];
		std::string	s1 = argv[2];
		std::string	s2 = argv[3];

		return (replaceInFile(filename, s1, s2));
	}
	else
		std::cerr << "Missing argumants!" << std::endl;
	return (0);
}
