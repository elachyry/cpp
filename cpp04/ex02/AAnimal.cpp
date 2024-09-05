/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:38:19 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/31 21:49:43 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : type("Animal")
{
	std::cout << "Animal Default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << "Animal Parameterized constructor called" << std::endl;
}
AAnimal::AAnimal(const AAnimal& animal)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = animal;
}

AAnimal::~AAnimal( void )
{
	std::cout << "Animal Destructor called" << std::endl;
}

AAnimal&	AAnimal::operator = (const AAnimal& animal)
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &animal)
	{
		this->type = animal.type;
	}
	return (*this);
}

std::string	AAnimal::getType( void ) const
{
	return (type);
}
