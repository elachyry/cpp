/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:29:49 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/04 21:03:05 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat)
{
	*this = bureaucrat;
}

Bureaucrat::~Bureaucrat( void )
{
	
}

Bureaucrat&	Bureaucrat::operator = (const Bureaucrat& bureaucrat)
{
	if (this != & bureaucrat)
		this->grade = bureaucrat.grade;
	return (*this);
}

const std::string	Bureaucrat::getName( void ) const
{
	return (this->name);
}

unsigned int	Bureaucrat::getGrade( void ) const
{
	return (this->grade);
}

void	Bureaucrat::Upgrade( void )
{
	if (this->grade > 1)
		this->grade--;
	else
		throw GradeTooHighException();
}

void	Bureaucrat::downgrade( void )
{
	if (this->grade < 150)
		this->grade++;
	else
		throw GradeTooLowException();
}

void	Bureaucrat::signForm( Form& form )
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << "." << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->name << " couldn't sign " << form.getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
}

const char	*Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ("Grade too high!");
}

const char	*Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ("Grade too low!");
}

std::ostream&	operator << (std::ostream& output, const Bureaucrat& bureaucrat)
{
	output << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (output);
}
