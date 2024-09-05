/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:45:11 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/30 20:26:40 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog : public Animal
{
	public:
		Dog( void );
		Dog( std::string type );
		Dog( const Dog& dog );
		~Dog( void );
		Dog&	operator = ( const Dog& dog );
		void	makeSound( void ) const;
};

#endif