/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:25:49 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/10 18:42:53 by melachyr         ###   ########.fr       */
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
		unsigned int	size( void );
	
};

# include "Array.tpp"

#endif