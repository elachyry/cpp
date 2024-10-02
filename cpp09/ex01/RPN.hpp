/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:30:06 by melachyr          #+#    #+#             */
/*   Updated: 2024/10/01 20:42:08 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <iomanip>
# include <cstdlib>
# include <stack>
# include <exception>

class	RPN
{
	private:
		std::string	expression;
		std::stack<float>	expStack;

	public:
		RPN( void );
		RPN( std::string );
		RPN( const RPN& );
		~RPN( void );
		RPN&	operator = ( const RPN& );
		float	process( void );
};

#endif