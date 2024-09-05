/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:44:33 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/31 15:50:08 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal
{
	private:
		Brain	*brain;
	
	public:
		Cat( void );
		Cat( const Cat& cat );
		~Cat( void );
		Cat&	operator = ( const Cat& cat );
		void	makeSound( void ) const ;
};

#endif