/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:02:55 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/06 02:48:12 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

Intern::Intern( void ) {}

Intern::Intern(const Intern& intern)
{
	*this = intern;
}

Intern::~Intern() {}

Intern&	Intern::operator = (const Intern& intern)
{
	(void) intern;
	return (*this);
}

AForm	*Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string	formNames[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm	*forms[3] = 
	{
		new RobotomyRequestForm(formTarget),
		new PresidentialPardonForm(formTarget),
		new ShrubberyCreationForm(formTarget)
	};
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formNames[i] << "." << std::endl;
			for (int j = i + 1; j < 3; j++)
				delete forms[j];
			return (forms[i]);
		}
		delete forms[i];
	}
	throw FormDoesNotExistException();
}

const char	*Intern::FormDoesNotExistException::what( void ) const throw()
{
	return ("Form name does not exist!");
}
