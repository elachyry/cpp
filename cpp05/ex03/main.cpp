/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:06:45 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/09 18:11:06 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main( void )
{
	AForm* rrf = NULL;
	AForm* ppf = NULL;
	AForm* scf = NULL;
	AForm* nrf = NULL;
	try
	{
		Bureaucrat	b("Mohammed", 2);
		Intern someRandomIntern1;
		rrf = someRandomIntern1.makeForm("robotomy request", "Bender");
		b.signForm(*rrf);
		b.executeForm(*rrf);

		Bureaucrat	b2("Adam", 5);
		Intern someRandomIntern2;
		ppf = someRandomIntern2.makeForm("presidential pardon", "Montassir");
		b2.signForm(*ppf);
		b2.executeForm(*ppf);

		Bureaucrat	b3("Amine", 12);
		Intern someRandomIntern3;
		scf = someRandomIntern3.makeForm("shrubbery creation", "House");
		b3.signForm(*scf);
		b3.executeForm(*scf);

		Intern someRandomIntern4;
		nrf = someRandomIntern4.makeForm("not real form", "House");

		delete rrf;
		delete ppf;
		delete scf;
	}
	catch(std::exception& e)
	{
		if (rrf)
			delete rrf;
		if (ppf)
			delete ppf;
		if (scf)
			delete scf;
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
