/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:34:56 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/31 21:48:15 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class	AAnimal
{
	protected:
		std::string	type;

	public:
		AAnimal( void );
		AAnimal( std::string type );
		AAnimal( const AAnimal& animal );
		virtual ~AAnimal( void );
		AAnimal&	operator = ( const AAnimal& animal );
		virtual void	makeSound( void ) const = 0;
		std::string	getType( void ) const;
};

#endif