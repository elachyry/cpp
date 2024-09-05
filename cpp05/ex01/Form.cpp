/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:50:58 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/04 22:02:26 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) : gradeToSign(0), gradeToExecute(0)
{
	this->isSigned = false;
}

Form::Form(const std::string name,
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

Form::Form(const Form& form)
	: name(form.name),
	gradeToSign(form.gradeToSign),
	gradeToExecute(form.gradeToExecute)
{
	this->isSigned = form.isSigned;
}

Form::~Form() {}

Form&	Form::operator = (const Form& form)
{
	if (this != &form)
	{
		this->isSigned = form.isSigned;
	}
	return (*this);
}

const std::string	Form::getName( void ) const
{
	return (this->name);
}

bool	Form::getIsSigned( void ) const
{
	return (this->isSigned);
}

unsigned int	Form::getGradeToSign( void ) const
{
	return (this->gradeToSign);
}

unsigned int	Form::getGradeToExecute( void ) const
{
	return (this->gradeToExecute);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
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

const char	*Form::GradeTooHighException::what( void ) const throw()
{
	return ("Grade too high!");
}

const char	*Form::GradeTooLowException::what( void ) const throw()
{
	return ("Grade too low!");
}

std::ostream&	operator << (std::ostream& output, const Form& form)
{
	output << form.getName() << ", Grade required to sign: " << form.getGradeToSign() 
			<< ", Grade required to execute: " << form.getGradeToExecute()
			<< ", is Form signed: " << (form.getIsSigned() ? "true" : "false") << ".";
	return (output);
}
