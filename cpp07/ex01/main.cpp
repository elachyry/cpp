/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:36:34 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/10 18:09:33 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T, typename F>
void	iter(T *tab, int const & size, F const & func)
{
	for (int i = 0; i < size; i++)
	{
		func(tab[i]);
	}
}
template<typename T>
void increment(T& i)
{
	++i;
}

int	main( void )
{
	int tab[5] = {1, 2, 3, 4, 5};
	iter(tab, 5, increment<int>);

	for (int i = 0; i < 5; i++)
	{
		std::cout << tab[i] << std::endl;
	}
	return (0);
}
