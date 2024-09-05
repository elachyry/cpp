/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:38:19 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/29 18:48:54 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : type("Animal")
{
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal Parameterized constructor called" << std::endl;
}
Animal::Animal(const Animal& animal)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = animal;
}

Animal::~Animal( void )
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal&	Animal::operator = (const Animal& animal)
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &animal)
	{
		this->type = animal.type;
	}
	return (*this);
}

void	Animal::makeSound( void ) const
{
	std::cout << "The animal makes a sound" << std::endl;
}

std::string	Animal::getType( void ) const
{
	return (type);
}
