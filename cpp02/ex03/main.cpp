/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:59:06 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/27 15:35:30 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main( void )
{
	//inside
	Point a(Fixed(0), Fixed(0));
	Point b(Fixed(10), Fixed(30));
	Point c(Fixed(20), Fixed(0));
	Point p(Fixed(10), Fixed(15));
	std::cout << (bsp(a, b, c ,p) ? "Inside" : "Outside") << std::endl;

	//outside
	// Point a(Fixed(0), Fixed(0));
	// Point b(Fixed(10), Fixed(30));
	// Point c(Fixed(20), Fixed(0));
	// Point p(Fixed(20), Fixed(0));
	// std::cout << (bsp(a, b, c ,p) ? "Inside" : "Outside") << std::endl;

	return (0);
}
