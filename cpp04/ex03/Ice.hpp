/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:15:47 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/04 15:16:05 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "LinkedList.hpp"

class	Ice : public AMateria
{
	public:
		Ice( void );
		Ice( const Ice& ice);
		~Ice( void );
		Ice&		operator = (const Ice& ice);
		void		*operator new ( size_t );
		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif