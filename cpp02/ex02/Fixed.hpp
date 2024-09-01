/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:35:46 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/01 14:02:36 by melachyr         ###   ########.fr       */
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
		Fixed( const int number );
		Fixed( const float number );
		Fixed( const Fixed& fixed );
		~Fixed( void );
		Fixed&				operator = (const Fixed& fixed);
		int					getRawBits( void ) const;
		void				setRawBits( int const raw );
		float				toFloat( void ) const;
		int					toInt( void ) const;
		bool				operator > (const Fixed& fixed) const;
		bool				operator >= (const Fixed& fixed) const;
		bool				operator < (const Fixed& fixed) const;
		bool				operator <= (const Fixed& fixed) const;
		bool				operator == (const Fixed& fixed) const;
		bool				operator != (const Fixed& fixed) const;
		Fixed				operator + (const Fixed& fixed) const;
		Fixed				operator - (const Fixed& fixed) const;
		Fixed				operator * (const Fixed& fixed) const;
		Fixed				operator / (const Fixed& fixed) const;
		Fixed&				operator ++ ( void );
		Fixed&				operator -- ( void );
		Fixed				operator ++ ( int );
		Fixed				operator -- ( int );
		static Fixed&		min(Fixed& fixed1, Fixed& fixed2);
		static Fixed&		max(Fixed& fixed1, Fixed& fixed2);
		static const Fixed&	min(const Fixed& fixed1, const Fixed& fixed2);
		static const Fixed&	max(const Fixed& fixed1, const Fixed& fixed2);
		
};
std::ostream&	operator << (std::ostream& output, const Fixed& fixed);

#endif