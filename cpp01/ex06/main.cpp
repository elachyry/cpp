/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:18:42 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/24 22:19:37 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "harl.hpp"

levels	getLevel(std::string level)
{
	if (level == "DEBUG") return (DEBUG);
	if (level == "INFO") return (INFO);
	if (level == "WARNING") return (WARNING);
	if (level == "ERROR") return (ERROR);
	return (OTHER);
}

int main(int argc, char **argv)
{
    Harl harl;

    if (argc == 2)
    {
		levels level = getLevel(argv[1]);
		switch (level)
		{
			case DEBUG:
				std::cout << "[DEBUG]" << std::endl;
				harl.complain("DEBUG");
				std::cout << std::endl;
			case INFO:
				std::cout << "[INFO]" << std::endl;
				harl.complain("INFO");
				std::cout << std::endl;
			case WARNING:
				std::cout << "[WARNING]" << std::endl;
				harl.complain("WARNING");
				std::cout << std::endl;
			case ERROR:
				std::cout << "[ERROR]" << std::endl;
				harl.complain("ERROR");
				std::cout << std::endl;
				break ;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		}
    }
    return (0);
}
