/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:45:39 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/31 15:53:32 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
	std::cout << "Dog Default constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = dog;
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
		this->brain = dog.brain;
	}
	return (*this);
}

void	Dog::makeSound( void ) const
{
	std::cout << "The " << type << " says: how howww!" << std::endl;
}
