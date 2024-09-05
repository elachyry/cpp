/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:50:58 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/04 22:45:56 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( void ) : gradeToSign(0), gradeToExecute(0)
{
	this->isSigned = false;
}

AForm::AForm(const std::string name,
	const unsigned int gradeToSign,
	unsigned int gradeToExecute)
	: name(name),
	gradeToSign(gradeToSign),
	gradeToExecute(gradeToExecute)
{
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw GradeTooHighException();
	else if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw GradeTooLowException();
	this->isSigned = false;
}

AForm::AForm(const AForm& form)
	: name(form.name),
	gradeToSign(form.gradeToSign),
	gradeToExecute(form.gradeToExecute)
{
	this->isSigned = form.isSigned;
}

AForm::~AForm() {}

AForm&	AForm::operator = (const AForm& form)
{
	if (this != &form)
	{
		this->isSigned = form.isSigned;
	}
	return (*this);
}

const std::string	AForm::getName( void ) const
{
	return (this->name);
}

bool	AForm::getIsSigned( void ) const
{
	return (this->isSigned);
}

unsigned int	AForm::getGradeToSign( void ) const
{
	return (this->gradeToSign);
}

unsigned int	AForm::getGradeToExecute( void ) const
{
	return (this->gradeToExecute);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (!this->isSigned)
		if (bureaucrat.getGrade() <= this->gradeToSign)
		{
			this->isSigned = true;
			std::cout << this->name << " Form signed by " << bureaucrat.getName() << " with grade " << bureaucrat.getGrade() << "." << std::endl;
		}
		else
			throw Bureaucrat::GradeTooLowException();
	else
		std::cout << this->name << " Form already signed." << std::endl;
}

void	AForm::checkExecutionRequirements(Bureaucrat const & executor) const
{
	if (!isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException();
}

const char	*AForm::GradeTooHighException::what( void ) const throw()
{
	return ("Grade too high!");
}

const char	*AForm::GradeTooLowException::what( void ) const throw()
{
	return ("Grade too low!");
}

const char	*AForm::FormNotSignedException::what( void ) const throw()
{
	return ("Form not signed!");
}

std::ostream&	operator << (std::ostream& output, const AForm& form)
{
	output << form.getName() << ", Grade required to sign: " << form.getGradeToSign() 
			<< ", Grade required to execute: " << form.getGradeToExecute()
			<< ", is Form signed: " << (form.getIsSigned() ? "true" : "false") << ".";
	return (output);
}
