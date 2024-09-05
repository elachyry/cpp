/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:24:37 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/04 15:15:19 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure")
{
	//std::cout << "Cure Default constructor called" << std::endl;
}

Cure::Cure(const Cure& cure)
{
	//std::cout << "Cure Copy constructor called" << std::endl;
	*this = cure;
}

Cure::~Cure()
{
	//std::cout << "Cure Destructor called" << std::endl;
}

Cure&	Cure::operator = (const Cure& cure)
{
	//std::cout << "Cure Copy assignment operator called" << std::endl;
	(void)cure;
	return (*this);
}

void		*Cure::operator new ( size_t t )
{
	void	*ptr = ::operator new(t);
	floor.addBack(ptr);
	return ptr;
}

AMateria*	Cure::clone() const
{
	return (new Cure());
}

void		Cure::use(ICharacter& target)
{
	std::cout <<  "* heals " << target.getName() <<"'s wounds *" << std::endl;
}
