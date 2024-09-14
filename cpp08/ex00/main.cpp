/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:36:34 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/14 16:00:38 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <deque>

int	main( void )
{
	std::cout << "Vector" <<std::endl;
	std::vector<int> v;

	for(int i = 0; i < 10; i++)
		v.push_back(i);
	
	try
	{
		std::vector<int>::const_iterator result = easyfind(v, 20);
		std::cout << *result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "Lsit" <<std::endl;
	std::list<int> l;
	
	for(int i = 0; i < 10; i++)
		l.push_back(i * 2);
	
	try
	{
		std::list<int>::const_iterator result = easyfind(l, 20);
		std::cout << *result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "deque" <<std::endl;
	std::deque<int> d;

	for(int i = 0; i < 10; i++)
		d.push_back(i * 3);

	try
	{
		std::deque<int>::const_iterator result = easyfind(d, 3);
		std::cout << *result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
