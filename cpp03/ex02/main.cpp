/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:59:06 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/03 20:07:59 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main( void )
{
	ClapTrap clapTrap1("boo");

	clapTrap1.attack("foo");
	clapTrap1.takeDamage(5);
	clapTrap1.beRepaired(3);
	clapTrap1.takeDamage(8);
	clapTrap1.attack("Too");

	std::cout << std::endl;
	
	FragTrap fragTrap;
	fragTrap.takeDamage(20);
	fragTrap.beRepaired(10);
	fragTrap.takeDamage(90);
	fragTrap.attack("Scav");
	fragTrap.highFivesGuys();
	return (0);
}
