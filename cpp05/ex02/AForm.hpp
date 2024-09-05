/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:38:44 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/05 16:41:25 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const unsigned int	gradeToSign;
		const unsigned int	gradeToExecute;

	protected:
		 void				checkExecutionRequirements(Bureaucrat const & executor) const;
		
	public:
		AForm( void );
		AForm( const std::string name, const unsigned int gradeToSign, unsigned int gradeToExecute );
		AForm( const AForm& form );
		virtual ~AForm( void );
		AForm&	operator = ( const AForm& form );
		const std::string	getName( void ) const;
		bool				getIsSigned( void ) const;
		unsigned int		getGradeToSign( void ) const;
		unsigned int		getGradeToExecute( void ) const;
		void				beSigned( const Bureaucrat& bureaucrat );
		virtual void		execute(Bureaucrat const & executor) const = 0;

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what( void ) const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what( void ) const throw();
		};

		class	FormNotSignedException : public std::exception
		{
			public:
				virtual const char	*what( void ) const throw();
		};
};

std::ostream&	operator << (std::ostream& output, const AForm& form);

#endif