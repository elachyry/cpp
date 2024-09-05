/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:06:45 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/04 18:40:54 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main( void )
{
	try
	{
		Bureaucrat	b("dsf", 149);
		b.downgrade();
		b.Upgrade();
		std::cout << b << std::endl;
		b.downgrade();
		b.downgrade();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}
