/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:45:39 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/05 23:52:23 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : AAnimal("Dog")
{
	std::cout << "Dog Default constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog& dog) : AAnimal(dog)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	this->type = dog.type;
	this->brain = new Brain(*dog.brain);
}

Dog::~Dog( void )
{
	std::cout << "Dog Destructor called" << std::endl;
	delete this->brain;
}

Dog&	Dog::operator = (const Dog& dog)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &dog)
	{
		this->type = dog.type;
		if (this->brain)
			delete this->brain;
		if (dog.brain)
			this->brain = new Brain(*dog.brain);
		else
			this->brain = NULL;
	}
	return (*this);
}

void	Dog::makeSound( void ) const
{
	std::cout << "The " << type << " says: how howww!" << std::endl;
}
