/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:59:20 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/09 17:01:01 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	private:
		const std::string	name;
		unsigned int		grade;

	public:
		Bureaucrat( std::string name, unsigned int grade );
		Bureaucrat( const Bureaucrat& bureaucrat );
		~Bureaucrat( void );
		Bureaucrat&			operator = ( const Bureaucrat& bureaucrat );
		const std::string	getName( void ) const;
		unsigned int		getGrade( void ) const;
		void				Upgrade( void );
		void				downgrade( void );


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