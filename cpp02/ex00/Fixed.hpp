/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:35:46 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/01 14:01:59 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int					fixedPoint;
		static const int	fraction;

	public:
		Fixed( void );
		Fixed( const Fixed& fixed );
		~Fixed( void );
		Fixed&	operator=(const Fixed& fixed);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif