/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:06:45 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/04 21:13:08 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main( void )
{
	try
	{
		Bureaucrat	b("Mohammed", 2);
		b.Upgrade();
		std::cout << b << std::endl;
		Form	f("Form1", 5, 2);
		std::cout << f << std::endl;
		f.beSigned(b);
		std::cout << f << std::endl;
		Bureaucrat	b2("Adam", 50);
		Form	f2("Form2", 10, 2);
		std::cout << b2 << std::endl;
		b2.signForm(f);
		b2.signForm(f2);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}
