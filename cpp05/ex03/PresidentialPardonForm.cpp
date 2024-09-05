/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 22:24:45 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/05 16:56:42 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(std::string target ) : AForm("PresidentialPardonForm", 25, 5)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& presidentialPardonForm) : AForm(presidentialPardonForm) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&	PresidentialPardonForm::operator = (const PresidentialPardonForm& presidentialPardonForm)
{
	(void) presidentialPardonForm;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	AForm::checkExecutionRequirements(executor);

	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
