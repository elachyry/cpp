/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 22:07:38 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/05 16:56:45 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", 72, 45) {}
RobotomyRequestForm::RobotomyRequestForm(std::string target ) : AForm("RobotomyRequestForm", 72, 45)
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& robotomyRequestForm) : AForm(robotomyRequestForm) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&	RobotomyRequestForm::operator = (const RobotomyRequestForm& robotomyRequestForm)
{
	(void) robotomyRequestForm;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::checkExecutionRequirements(executor);

	std::cout << "Drilling noises: Drrrrr Zrrrrrr....." << std::endl;

	std::srand(std::time(0));

	if (std::rand() % 2 == 0)
		std::cout << this->target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->target << " robotomy failed." << std::endl;
}
