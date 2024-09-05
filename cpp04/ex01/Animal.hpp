/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:34:56 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/29 23:26:06 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class	Animal
{
	protected:
		std::string	type;

	public:
		Animal( void );
		Animal( std::string type );
		Animal( const Animal& animal );
		virtual ~Animal( void );
		Animal&	operator = ( const Animal& animal );
		virtual void	makeSound( void ) const;
		std::string	getType( void ) const;
};

#endif