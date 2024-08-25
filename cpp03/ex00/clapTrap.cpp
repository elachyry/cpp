/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:58:43 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/25 23:53:27 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clapTrap.hpp"

ClapTrap::ClapTrap( void ) : hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Name constructor called" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& clapTrap )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = clapTrap;
}

ClapTrap&	ClapTrap::operator = ( const ClapTrap& clapTrap )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &clapTrap)
	{
		this->name = clapTrap.name;
		this->hitPoints = clapTrap.hitPoints;
		this->energyPoints = clapTrap.energyPoints;
		this->attackDamage = clapTrap.attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints && this->hitPoints)
	{
		std::cout << "ClapTrap " << this->name <<" attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->name << " does not have enough energy to attack." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->hitPoints)
		this->hitPoints = 0;
	else
		this->hitPoints -= amount;
	std::cout << "ClapTrap " << this->name << " has taken " << amount << " damage and now has " << this->hitPoints << " hit points left." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints)
	{	
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " has been repaired by " << amount << " points and now has " << this->hitPoints << " hit points and " << this->energyPoints << " energy points left." << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->name << " does not have enough energy to repair." << std::endl;
}
