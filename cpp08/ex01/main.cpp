/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:36:34 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/14 22:30:32 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main( void )
{
	try
	{
		std::vector<int> source;
		srand(time(0));
		for (int i = 1; i < 100; i++)
			source.push_back(i * (rand() % 60));
		Span sp(100);
		sp.addRange(source.begin(), source.end());
		// sp.addNumber(6);
		// sp.addNumber(3);
		// sp.addNumber(17);
		// sp.addNumber(9);
		// sp.addNumber(11);
		// sp.addNumber(18);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}
