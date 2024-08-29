/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:57:20 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/29 16:00:03 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	name;

	public:
		DiamondTrap( void );
		DiamondTrap( std::string name );
		DiamondTrap(const DiamondTrap& diamondTrap );
		~DiamondTrap( void );
		DiamondTrap&	operator = (const DiamondTrap& diamondTrap );
		void			whoAmI( void );
};

#endif