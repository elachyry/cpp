/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:09:48 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/27 15:23:23 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string name);
        void    setWeapon(Weapon& weapon);
        void    attack( void );

    private:
        Weapon*     weapon;
        std::string name;
};

#endif