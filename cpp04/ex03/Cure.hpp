/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:50:49 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/04 15:15:07 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "LinkedList.hpp"

class	Cure : public AMateria
{
	public:
		Cure( void );
		Cure( const Cure& cure);
		~Cure( void );
		Cure&		operator = (const Cure& cure);
		void		*operator new ( size_t );
		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif