/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:35:46 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/27 15:31:30 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public:
		Fixed( void );
		Fixed( const int number );
		Fixed( const float number );
		Fixed( const Fixed& fixed );
		Fixed& operator=(const Fixed& fixed);
		~Fixed( void );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		int					fixedPoint;
		static const int	fraction = 8;
	
};
std::ostream&	operator << (std::ostream& output, const Fixed& fixed);

#endif