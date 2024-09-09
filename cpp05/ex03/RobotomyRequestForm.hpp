/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 22:06:36 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/09 18:14:39 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
	private:
		std::string	target;

	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm& );
		~RobotomyRequestForm( void );
		RobotomyRequestForm&	operator = ( const RobotomyRequestForm& );
		void					execute(Bureaucrat const & executor) const;
};

#endif