/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 22:09:57 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/04 16:23:09 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "LinkedList.hpp"

class Character : public ICharacter
{
	private:
		std::string	name;
		AMateria	*slots[4];

	public:
		Character( void );
		Character( std::string name );
		Character( const Character& character );
		~Character( void );
		Character&			operator = ( const Character& character );
		std::string const &	getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
};

#endif