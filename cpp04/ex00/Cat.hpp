/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:44:33 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/29 18:49:05 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class	Cat : public Animal
{
	public:
		Cat( void );
		Cat( std::string type );
		Cat( const Cat& cat );
		~Cat( void );
		Cat&	operator = ( const Cat& cat );
		void	makeSound( void ) const ;
};

#endif