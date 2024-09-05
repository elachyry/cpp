/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:45:23 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/05 23:51:22 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	std::cout << "Cat Default constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	this->type = cat.type;
	this->brain = new Brain(*cat.brain);
}

Cat::~Cat( void )
{
	std::cout << "Cat Destructor called" << std::endl;
	delete this->brain;
}

Cat&	Cat::operator = (const Cat& cat)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &cat)
	{
		this->type = cat.type;
		if (this->brain)
			delete this->brain;
		
		if (cat.brain)
			this->brain = new Brain(*cat.brain);
		else
			this->brain = NULL;
	}
	return (*this);
}

void	Cat::makeSound( void ) const 
{
	std::cout << "The " << type << " says: meaw meaaaaw!" << std::endl;
}
