/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:59:06 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/29 16:18:04 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main( void )
{
	DiamondTrap diamondTrap("boo");

	diamondTrap.whoAmI();
	diamondTrap.guardGate();
	diamondTrap.highFivesGuys();
	diamondTrap.attack("med");
	diamondTrap.takeDamage(50);
	diamondTrap.beRepaired(10);
	return (0);
}
