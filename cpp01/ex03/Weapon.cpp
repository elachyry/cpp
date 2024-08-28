/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:49:19 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/27 17:35:43 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void ) {}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

const std::string&	Weapon::getType( void )
{
	return (this->type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}
