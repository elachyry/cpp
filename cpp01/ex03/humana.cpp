/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humana.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:12:36 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/23 17:54:37 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "humana.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon){}

void    HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
