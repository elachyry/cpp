/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:03:16 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/31 17:22:47 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain& brain)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = brain;
}

Brain::~Brain( void )
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain&	Brain::operator = (const Brain& brain)
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &brain)
	{
		for (int i = 0; i < (int)brain.ideas->size(); i++)
		{
			this->ideas[i] = brain.ideas[i];
		}
	}
	return (*this);
}
