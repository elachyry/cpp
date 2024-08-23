/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:49:19 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/23 17:48:56 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "weapon.hpp"

Weapon::Weapon( void ) {}

Weapon::Weapon(std::string type)
{
    this->type = type;
}

const std::string&   Weapon::getType( void )
{
    return (this->type);
}

void    Weapon::setType(std::string type)
{
    this->type = type;
}
