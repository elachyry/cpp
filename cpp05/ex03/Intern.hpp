/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:03:01 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/05 16:29:08 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern
{
	private:
		
	public:
		Intern( void );
		Intern( const Intern& intern );
		~Intern( void );
		Intern&	operator = ( const Intern& intern );
		AForm	*makeForm(std::string formName, std::string formTarget);

		class	FormDoesNotExistException : public std::exception
		{
			public:
				virtual const char	*what( void ) const throw();
		};
};

#endif