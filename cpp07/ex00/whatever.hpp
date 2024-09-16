/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 01:39:12 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/16 16:20:24 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void	swap( T&, T& );

template<typename T>
T const &	min( T const &, T const & );

template<typename T>
T const &	max( T const &, T const & );

template<typename T>
void	swap(T& a, T& b)
{
	T	c;

	c = a;
	a = b;
	b = c;
}

template<typename T>
T const &	min( T const & a, T const & b)
{
	return (a < b ? a : b);
}

template<typename T>
T const &	max( T const & a, T const & b)
{
	return (a >= b ? a : b);
}

#endif