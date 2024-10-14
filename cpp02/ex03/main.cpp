/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:59:06 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/13 02:08:19 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main( void )
{
	//inside
	{
		Point a(Fixed(0), Fixed(0));
		Point b(Fixed(4), Fixed(0));
		Point c(Fixed(2), Fixed(3));
		Point p(Fixed(2), Fixed(1));
		std::cout << (bsp(a, b, c ,p) ? "Inside" : "Outside") << std::endl;
	}

	//outside
	{
		Point a(Fixed(0), Fixed(0));
		Point b(Fixed(4), Fixed(0));
		Point c(Fixed(2), Fixed(3));
		Point p(Fixed(5), Fixed(2));
		std::cout << (bsp(a, b, c ,p) ? "Inside" : "Outside") << std::endl;
	}

	//One of the Triangle's Legs
	{
		Point a(Fixed(0), Fixed(0));
		Point b(Fixed(4), Fixed(0));
		Point c(Fixed(2), Fixed(3));
		Point p(Fixed(3), Fixed(2));
		std::cout << (bsp(a, b, c ,p) ? "Inside" : "Outside") << std::endl;
	}

	return (0);
}
