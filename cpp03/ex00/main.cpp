/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:59:06 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/27 15:36:24 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap clapTrap1("boo");

	clapTrap1.attack("foo");
	clapTrap1.takeDamage(5);
	clapTrap1.beRepaired(3);
	clapTrap1.takeDamage(8);
	clapTrap1.attack("Too");

	return (0);
}
