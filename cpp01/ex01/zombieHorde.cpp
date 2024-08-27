/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:43:56 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/27 15:20:42 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return (NULL);
    Zombie  *zombie = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        new (zombie + i) Zombie(name);
    }
    return (zombie);
}
