/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:06:54 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/14 22:23:34 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class	Span
{
	private:
		unsigned int		N;
		std::vector<int>	data;

	public:
		Span( void );
		Span( unsigned int );
		Span( const Span& );
		~Span( void );
		Span&	operator = ( const Span& );
		void	addNumber( int );
		int		shortestSpan( void );
		int		longestSpan( void );

		template<typename I>
		void	addRange( I begin, I end)
		{
			if (std::distance(begin, end) + data.size() > N)
				throw std::out_of_range("Exception: You cannot add the range, because span will exceed max size!");
			data.insert(data.end(), begin, end);
		}
};

#endif