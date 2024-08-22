/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:43:56 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/22 18:41:09 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie  *zombie = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        new (zombie + i) Zombie(name);
    }
    return (zombie);
}
