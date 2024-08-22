/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:41:55 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/22 17:38:44 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>


class Zombie
{
    public:
        Zombie( std::string name );
        ~Zombie();
        void    announce( void );
    private:
        std::string name;
};


void    randomChump(std::string name);
Zombie  *newZombie(std::string name);

#endif