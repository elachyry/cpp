/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:06:45 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/05 16:01:14 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main( void )
{
	try
	{
		Bureaucrat	b("Mohammed", 2);
		b.Upgrade();
		std::cout << b << std::endl;
		ShrubberyCreationForm	f1("House");
		f1.beSigned(b);
		b.executeForm(f1);

		Bureaucrat	b2("Adam", 12);
		RobotomyRequestForm	f2("House");
		f2.beSigned(b2);
		b2.executeForm(f2);

		Bureaucrat	b3("Amine", 5);
		PresidentialPardonForm	f3("Montassir");
		f3.beSigned(b3);
		b3.executeForm(f3);
	
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}
