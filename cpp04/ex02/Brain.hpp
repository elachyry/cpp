	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:44:48 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/31 15:48:11 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string	ideas[100];	

	public:
		Brain( void );
		Brain( const Brain& brain );
		~Brain( void );
		Brain&	operator = ( const Brain& brain );
};

#endif
