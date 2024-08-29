/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:10:55 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/29 14:52:35 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "FragTrap Name constructor called" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap( const FragTrap& fragTrap)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = fragTrap;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap&	FragTrap::operator = ( const FragTrap& fragTrap)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &fragTrap)
	{
		this->name = fragTrap.name;
		this->hitPoints = fragTrap.hitPoints;
		this->energyPoints = fragTrap.energyPoints;
		this->attackDamage = fragTrap.attackDamage;
	}
	return (*this);	
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap is requesting high fives from you guys!" << std::endl;
}
