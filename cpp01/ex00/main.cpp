/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:11:44 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/22 17:39:48 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int main( void )
{
    Zombie *zombie = newZombie("boo");
    zombie->announce();
    delete zombie;
    randomChump("zoo");
    return (0);
}
