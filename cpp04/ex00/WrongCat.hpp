/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:44:33 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/31 16:49:37 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	public:
		WrongCat( void );
		WrongCat( std::string type );
		WrongCat( const WrongCat& wrongCat );
		~WrongCat( void );
		WrongCat&	operator = ( const WrongCat& wrongCat );
		void	makeSound( void ) const ;
};

#endif