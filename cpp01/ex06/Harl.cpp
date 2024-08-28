/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:33:27 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/27 22:30:03 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl << "I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl << "You didn't put enough bacon in my burger!" << std::endl << "If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl << "I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void (Harl::*funcPtr[])() = 
	{
		&Harl::debug, 
		&Harl::info, 
		&Harl::warning, 
		&Harl::error
	};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	Harl harl;
	for (int i = 0; i < (int)levels->size(); i++)
	{
		if (levels[i] == level)
			(harl.*funcPtr[i])();
	}
}
