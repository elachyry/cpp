/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:59:20 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/10 01:21:36 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class	Form;

class Bureaucrat
{
	private:
		const std::string	name;
		unsigned int		grade;

	public:
		Bureaucrat( void );
		Bureaucrat( std::string name, unsigned int grade );
		Bureaucrat( const Bureaucrat& bureaucrat );
		~Bureaucrat( void );
		Bureaucrat&			operator = ( const Bureaucrat& bureaucrat );
		const std::string	getName( void ) const;
		unsigned int		getGrade( void ) const;
		void				Upgrade( void );
		void				downgrade( void );
		void				signForm( Form& form );


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

std::ostream&	operator << (std::ostream& output, const Bureaucrat& bureaucrat);


#endif