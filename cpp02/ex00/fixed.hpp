/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:35:46 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/24 23:06:07 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public:
		Fixed( void );
		Fixed( Fixed& fixed );
		Fixed& operator=(const Fixed& fixed);
		~Fixed( void );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					fixedPoint;
		static const int	fraction = 8;
	
};

#endif