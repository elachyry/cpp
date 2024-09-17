/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:25:49 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/16 18:02:46 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template<typename T>
class	Array
{
	private:
		T*				data;
		unsigned int	n;
	public:
		Array( void );
		Array( unsigned int );
		Array( const Array<T>& );
		~Array( void );
		Array<T>&		operator = ( const Array<T>& );
		T&				operator [] ( unsigned int );
		T const &		operator [] ( unsigned int ) const;
		unsigned int	size( void ) const;
	
};

# include "Array.tpp"

#endif