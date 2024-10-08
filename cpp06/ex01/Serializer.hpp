/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:18:39 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/13 18:43:52 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <stdint.h>
# include <fstream>

class	Serializer
{
	private:
		Serializer( void );
		Serializer( const Serializer& );
		
	public:
		~Serializer( void );
		Serializer&			operator = ( const Serializer& );
		static uintptr_t	serialize( Data* );
		static Data*		deserialize( uintptr_t );
};

#endif