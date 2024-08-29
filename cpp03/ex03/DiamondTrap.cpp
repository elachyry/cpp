/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:57:09 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/29 16:09:25 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), name(name)
{
	std::cout << "DiamondTrap Name constructor called" << std::endl;
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) : ClapTrap(diamondTrap), ScavTrap(diamondTrap), FragTrap(diamondTrap)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	*this = diamondTrap;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator = (const DiamondTrap& diamondTrap)
{
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	if (this != &diamondTrap)
	{
		this->name = diamondTrap.name;
		this->ClapTrap::name = diamondTrap.ClapTrap::name;
		this->hitPoints = diamondTrap.hitPoints;
		this->energyPoints = diamondTrap.energyPoints;
		this->attackDamage = diamondTrap.attackDamage;
	}
	return (*this);
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "DiamondTrap name : " << name << " ,ClapTrap name : " << ClapTrap::name << std::endl;
}
