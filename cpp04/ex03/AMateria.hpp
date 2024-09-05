/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:50:42 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/02 23:12:12 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class	ICharacter;

class AMateria
{
	protected:
		std::string	type;

	public:
		AMateria( void );
		AMateria(std::string const & type);
		AMateria( const AMateria& materia);
		virtual ~AMateria( void );
		AMateria&	operator = (const AMateria& materia);
		std::string const &	getType() const;
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif