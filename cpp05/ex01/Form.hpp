/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:38:44 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/09 17:00:53 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const unsigned int	gradeToSign;
		const unsigned int	gradeToExecute;
		
	public:
		Form( void );
		Form( const std::string name, const unsigned int gradeToSign, unsigned int gradeToExecute );
		Form( const Form& form );
		~Form( void );
		Form&	operator = ( const Form& form );
		const std::string	getName( void ) const;
		bool				getIsSigned( void ) const;
		unsigned int		getGradeToSign( void ) const;
		unsigned int		getGradeToExecute( void ) const;
		void				beSigned( const Bureaucrat& bureaucrat );

		class	GradeTooHighException : public std::exception
		{
			public:
				const char	*what( void ) const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				const char	*what( void ) const throw();
		};
};

std::ostream&	operator << (std::ostream& output, const Form& form);

#endif