/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:36:34 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/10 20:20:50 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"


int	main( void )
{
	try
	{
		Array<float> data(5);
		Array<float> data2 = data;

		for (unsigned int i = 0; i < data2.size(); i++)
			data2[i] = i + 1.5;
		for (unsigned int i = 0; i < data2.size(); i++)
			std::cout << data2[i] << std::endl;
		std::cout << data2.size() << std::endl;
		std::cout << data[5] << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
