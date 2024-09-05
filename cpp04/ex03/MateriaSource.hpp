/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:18:29 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/03 14:39:14 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "Cure.hpp"
# include "Ice.hpp"
# include "LinkedList.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*materias[4];
	
	public:
		MateriaSource( void );
		MateriaSource( const MateriaSource& materiaSource );
		~MateriaSource( void );
		MateriaSource&	operator = ( const MateriaSource& materiaSource );
		void			learnMateria(AMateria*);
		AMateria*		createMateria(std::string const & type);
};

#endif