/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:45:11 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/31 21:49:59 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class	Dog : public AAnimal
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