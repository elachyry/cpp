/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 01:51:03 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/16 17:35:05 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T, typename F>
void	iter( T *, int const &, F const & );

template<typename T, typename F>
void	iter(T *tab, int const & size, F const & func)
{
	if (!tab || !func)
		return ;
	for (int i = 0; i < size; i++)
	{
		func(tab[i]);
	}
}

#endif