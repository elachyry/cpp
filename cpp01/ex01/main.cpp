/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:11:44 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/27 16:43:44 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
	int n = 10;
	Zombie *zombie = zombieHorde(n, "boo");
	for (int i = 0; i < n; i++)
		zombie->announce();
	delete[] zombie;
	return (0);
}
