/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:38:19 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/31 16:48:39 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("WrongAnimal")
{
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "WrongAnimal Parameterized constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	*this = wrongAnimal;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator = (const WrongAnimal& wrongAnimal)
{
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	if (this != &wrongAnimal)
	{
		this->type = wrongAnimal.type;
	}
	return (*this);
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "The WrongAnimal makes a sound" << std::endl;
}

std::string	WrongAnimal::getType( void ) const
{
	return (type);
}
