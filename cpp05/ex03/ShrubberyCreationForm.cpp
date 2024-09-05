/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:43:33 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/05 17:05:23 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", 145, 137) {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target ) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& shrubberyCreationForm) : AForm(shrubberyCreationForm) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator = (const ShrubberyCreationForm& shrubberyCreationForm)
{
	(void) shrubberyCreationForm;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::checkExecutionRequirements(executor);

	std::string	fileName = this->target + "_shrubbery";
	std::ofstream file(fileName.c_str());

	if (file)
	{	
		file << "         v .   ._, |_  .," << std::endl;
		file << "`-._\\/  .  \\ /    |/_\\" << std::endl;
		file << "\\  _\\, y | \\//\\" << std::endl;
		file << "_\\_.___\\, \\/ -.\\||\\" << std::endl;
		file << "`7-,--.`._||  / / ,\\" << std::endl;
		file << "/'     `-. `./ / |/_.'\\" << std::endl;
		file << "|    |//\\" << std::endl;
		file << "|_    /\\" << std::endl;
		file << "|-   |\\" << std::endl;
		file << "|   =|\\" << std::endl;
		file << "|    |\\" << std::endl;
		file << "--------------------/ ,  . \\--------._" << std::endl;
		file.close();
	}

}
