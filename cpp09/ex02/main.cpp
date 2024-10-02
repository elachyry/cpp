/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:36:34 by melachyr          #+#    #+#             */
/*   Updated: 2024/10/01 20:47:53 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	printVector(const Vector& vector)
{
	if (vector.size() > 10)
	{
		for(size_t i = 0; i < 10; i++)
			std::cout << vector[i] << " ";
		std::cout << " [...]";
	}
	else
	{
		for(size_t i = 0; i < vector.size(); i++)
		{
			std::cout << vector[i] << " ";
		}
	}
	std::cout << std::endl;
}

void	printDeque(const Deque& deque)
{

	for(size_t i = 0; i < deque.size(); i++)
	{
		std::cout << deque[i] << " ";
	}
	std::cout << std::endl;
}

bool	checkIfNumeric(std::string str)
{
	if (str.empty())
		return (false);
	
	std::string::iterator it = str.begin();
	std::string::iterator ite = str.end();
	
	for (; it != ite; it++)
	{
		if (*it == '+' && it == str.begin())
			continue ;
		if (!std::isdigit(*it))
			return (false);
	}
	return (true);
}
template<typename T>
bool	is_sorted(const T& cont)
{
	for (size_t i = 1; i < cont.size(); i++)
	{
		if (cont[i] < cont[i - 1])
		{
			std::cout << "[" << cont[i - 1] << " | " << cont[i] << "]" << std::endl;
			return (false);
		}
	}
	return (true);
}

int	printError( void )
{
	std::cout << "Error" << std::endl;
	return (1);
}

int	main(int argc, char **argv)
{
	Vector		vect;
	Deque		deque;
	PmergeMe	p;
	clock_t		start, end;

	if (argc < 2)
		return (printError());
	
	for (int i = 1; argv[i]; i++)
	{
		if (!checkIfNumeric(argv[i]))
			return (printError());
		int	n = std::atoi(argv[i]);
		if (n < 0)
			return (printError());
		if (std::find(vect.begin(), vect.end(), n) != vect.end())
			return (printError());
		vect.push_back(n);
		deque.push_back(n);
	}
	std::cout << std::setw(10) << std::left << "Before: ";
	printVector(vect);
	start = clock();
	p.fordJohnsonSortVector(vect);
	end = clock();
	double time_taken = double(end - start) / static_cast<double>(CLOCKS_PER_SEC);
	std::cout << std::setw(10) << std::left << "after: ";
	printVector(vect);
	std::cout << "Time to process a range of " << vect.size() << " elements with std::vector : " << std::fixed << time_taken << std::setprecision(6) << " us" << std::endl;
	//std::cout << "Vector is sorted " << (is_sorted(vect) ? "true" : "false") << std::endl;
	start = clock();
	p.fordJohnsonSortDeque(deque);
	//std::cout << "Deque is sorted " << (is_sorted(deque) ? "true" : "false") << std::endl;
	end = clock();
	time_taken = double(end - start) / static_cast<double>(CLOCKS_PER_SEC); 
	std::cout << "Time to process a range of " << vect.size() << " elements with std::deque : " << std::fixed << time_taken << std::setprecision(6) << " us" << std::endl;
	vect.clear();
	deque.clear();
	return (0);
}
