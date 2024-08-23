/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humana.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:09:48 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/23 17:54:50 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string name, Weapon& weapon);
        void    attack();

    private:
        std::string name;
        Weapon&     weapon;
};

#endif