/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanb.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:12:36 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/23 18:07:09 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "humanb.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
}

void    HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

void    HumanB::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
