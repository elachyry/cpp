/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:45:23 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/31 16:50:47 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& wrongCat) : WrongAnimal(wrongCat)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = wrongCat;
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat&	WrongCat::operator = (const WrongCat& wrongCat)
{
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	if (this != &wrongCat)
	{
		this->type = wrongCat.type;
	}
	return (*this);
}

void	WrongCat::makeSound( void ) const 
{
	std::cout << "The " << type << " says: meaw meaaaaw!" << std::endl;
}
