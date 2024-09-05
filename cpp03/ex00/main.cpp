/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:59:06 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/03 20:02:51 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap clapTrap1("asdasdasdasd");
	ClapTrap clapTrap2("asdasdasdasd");

	clapTrap1 = clapTrap2;
	clapTrap1.takeDamage(10);
	clapTrap1.attack("foo");
	clapTrap1.beRepaired(3);
	clapTrap1.takeDamage(8);
	clapTrap1.attack("Too");

	return (0);
}
