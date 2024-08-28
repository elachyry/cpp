/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:53:54 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/27 17:35:56 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
    public:
        Weapon( void );
        Weapon(std::string type);
        const std::string&	getType( void );
        void				setType(std::string type);

    private:
        std::string type;
};

#endif