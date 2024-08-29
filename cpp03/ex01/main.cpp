/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:59:06 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/29 14:04:43 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main( void )
{
	ClapTrap clapTrap1("boo");

	clapTrap1.attack("foo");
	clapTrap1.takeDamage(5);
	clapTrap1.beRepaired(3);
	clapTrap1.takeDamage(8);
	clapTrap1.attack("Too");

	ScavTrap scavTrap;
	scavTrap.takeDamage(20);
	scavTrap.beRepaired(10);
	scavTrap.takeDamage(20);
	scavTrap.attack("Clap");
	scavTrap.guardGate();
	return (0);
}
