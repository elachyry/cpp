/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:41:55 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/27 15:20:42 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>


class Zombie
{
    public:
        Zombie( void );
        Zombie( std::string name );
        ~Zombie();
        void    announce( void );
    private:
        std::string name;
};


Zombie* zombieHorde( int N, std::string name );

#endif