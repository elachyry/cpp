/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:36:34 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/20 00:53:18 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	printVector(const Vector& vector)
{
	for(size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}

void	printList(List list)
{
	Iterator start = list.begin();
	Iterator end = list.end();

	for (Iterator it = start; it != end; it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int	main( void )
{
	PmergeMe p;

	Vector vect;
	
	vect.push_back(8);
	vect.push_back(1);
	vect.push_back(0);
	vect.push_back(5);
	vect.push_back(3);
	vect.push_back(9);
	vect.push_back(2);
	vect.push_back(4);
	vect.push_back(6);
	vect.push_back(7);
	std::cout << std::setw(10) << std::left << "Before: ";
	printVector(vect);

	
	clock_t start, end; 
	start = clock();
	
	std::ios_base::sync_with_stdio(false);
	
	p.mergeSortVector(vect);
	
	end = clock();
	
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	std::cout << std::setw(10) << std::left << "after: ";
	printVector(vect);

	std::cout << "Time to process a range of " << vect.size() << " elements with std::vector : " << std::fixed << time_taken << std::setprecision(5) << " us" << std::endl;
	// std::cout << "List" << std::endl;
	List list;
	list.push_back(8);
	list.push_back(1);
	list.push_back(0);
	list.push_back(5);
	list.push_back(3);
	list.push_back(9);
	list.push_back(2);
	list.push_back(4);
	list.push_back(6);
	list.push_back(7);
	// printList(list);
	start = clock();
	p.mergeSortList(list);
	// for(size_t i = 0; i < 999999999; i++){}
	end = clock();
	time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
	std::cout << "Time to process a range of " << vect.size() << " elements with std::list : " << std::fixed << time_taken << std::setprecision(5) << " us" << std::endl;

	return (0);
}
