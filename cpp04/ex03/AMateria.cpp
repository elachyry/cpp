/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:47:38 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/02 23:56:42 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void )
{
	//std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& materia)
{
	//std::cout << "AMateria Copy constructor called" << std::endl;
	*this = materia;
}

AMateria::AMateria(std::string const & type)
{
	//std::cout << "AMateria Parameterized constructor called" << std::endl;
	this->type = type;
}

AMateria::~AMateria()
{
	//std::cout << "AMateria Destructor called" << std::endl;
}

AMateria&	AMateria::operator = (const AMateria& materia)
{
	//std::cout << "AMateria Copy assignment operator called" << std::endl;
	(void)materia;
	return (*this);
}

std::string const &	AMateria::getType() const
{
	return (this->type);
}

void		AMateria::use(ICharacter& target)
{
	std::cout << target.getName();
}

