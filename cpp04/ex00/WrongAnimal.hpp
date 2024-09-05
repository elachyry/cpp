/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:34:56 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/31 16:51:56 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class	WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal( void );
		WrongAnimal( std::string type );
		WrongAnimal( const WrongAnimal& wrongAnimal );
		~WrongAnimal( void );
		WrongAnimal&	operator = ( const WrongAnimal& wrongAnimal );
		void	makeSound( void ) const;
		std::string	getType( void ) const;
};

#endif