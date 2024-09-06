/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:19:14 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/06 02:24:31 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice")
{
	//std::cout << "Ice Default constructor called" << std::endl;
}

Ice::Ice(const Ice& ice)
{
	//std::cout << "Ice Copy constructor called" << std::endl;
	*this = ice;
}

Ice::~Ice()
{
	//std::cout << "Ice Destructor called" << std::endl;
}

Ice&	Ice::operator = (const Ice& ice)
{
	//std::cout << "Ice Copy assignment operator called" << std::endl;
	(void)ice;
	return (*this);
}

void	*Ice::operator new ( size_t t )
{
	void	*ptr = ::operator new(t);
	floor.addBack(ptr);
	return ptr;
}

AMateria*	Ice::clone() const
{
	return (new Ice());
}

void		Ice::use(ICharacter& target)
{
	std::cout <<  "* shoots an ice bolt at " << target.getName() <<" *" << std::endl;
}
