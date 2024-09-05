/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:44:33 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/31 21:50:02 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class	Cat : public AAnimal
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