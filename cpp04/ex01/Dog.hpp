/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:45:11 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/31 15:53:46 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal
{
	private:
		Brain	*brain;
	public:
		Dog( void );
		Dog( const Dog& dog );
		~Dog( void );
		Dog&	operator = ( const Dog& dog );
		void	makeSound( void ) const;
};

#endif