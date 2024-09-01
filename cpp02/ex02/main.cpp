/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:59:06 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/01 15:47:47 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void )
{
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}

	std::cout << "******************************************" << std::endl;
	
	{
		Fixed a(4);
		Fixed d(2.5f);
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		Fixed const c( Fixed( 10 ) / Fixed( 2.5f ) );
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		std::cout << a << " < " << d << " : " << ((a < d) ? "true" : "false") << std::endl;
		std::cout << a << " <= " << d << " : " << ((a <= d) ? "true" : "false") << std::endl;
		std::cout << a << " > " << d << " : " << ((a > d) ? "true" : "false") << std::endl;
		std::cout << a << " >= " << d << " : " << ((a >= d) ? "true" : "false") << std::endl;
		std::cout << a << " == " << d << " : " << ((a == d) ? "true" : "false") << std::endl;
		std::cout << a << " != " << d << " : " << ((a != d) ? "true" : "false") << std::endl;
		std::cout << a << " + " << d << " = " << a + d << std::endl;
		std::cout << a << " - " << d << " = " << a - d << std::endl;
		std::cout << a << " * " << d << " = " << a * d << std::endl;
		std::cout << a << " / " << d << " = " << a / d << std::endl;
		std::cout << "a++" << " = " << a++ << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "a--" << " = " << a-- << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "++a" << " = " << ++a << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "--a" << " = " << --a << std::endl;
		std::cout << "a = " << a << std::endl;
		std::cout << "min(" << a << ", " << d << ") = " << Fixed::min(a, d) << std::endl;
		std::cout << "max(" << a << ", " << d << ") = " << Fixed::max(a, d) << std::endl;
	}
	return (0);
}
