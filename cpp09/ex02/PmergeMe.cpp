/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:32:46 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/29 18:43:41 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void ) {}

PmergeMe::PmergeMe(const PmergeMe& pmergeMe)
{
	*this = pmergeMe;
}

PmergeMe::~PmergeMe( void ) {}

PmergeMe&	PmergeMe::operator = (const PmergeMe& pmergeMe)
{
	if (this != &pmergeMe)
	{
	}
	return (*this);
}

void	printVector2(const Vector& vector)
{
	for(size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::fordJohnsonSortVector(Vector& arr)
{
	int n = arr.size();
	if (n <= 1) return;

	std::sort(arr.begin(), arr.begin() + std::min(3, n));

	Vector sortedArr(arr.begin(), arr.begin() + 3);

	for (int i = 3; i < n; i += 2)
	{
		int a = arr[i];
		//std::cout << "a = " << a << std::endl;
		int b = (i + 1 < n) ? arr[i + 1] : INT_MAX;
		//std::cout << "b = " << b << std::endl;

		if (a > b) std::swap(a, b);

		binaryInsertVector(sortedArr, sortedArr.size(), a);

		if (b != INT_MAX)
			binaryInsertVector(sortedArr, sortedArr.size(), b);
	}
	std::copy(sortedArr.begin(), sortedArr.end(), arr.begin());
}

void	PmergeMe::binaryInsertVector(Vector& arr, int sortedEnd, int key)
{
	int left = 0, right = sortedEnd - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		//std::cout << "left = " << left << std::endl;
		//std::cout << "right = " << right << std::endl;
		//std::cout << "mid = " << mid << std::endl;
		if (arr[mid] == key)
		{
			arr.insert(arr.begin() + mid + 1, key);
			return;
		}
		if (arr[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;
	}
	arr.insert(arr.begin() + left, key);
}

void	increment(Iterator& it, int steps)
{
	for (int i = 0; i < steps; i++)
		it++;
}

void	PmergeMe::fordJohnsonSortList(List& list)
{
	int n = list.size();
	if (n <= 1) return;

	Iterator it = list.begin();
	increment(it, std::min(3, n));
	//std::sort(list.begin(), it);

	List sortedArr(list.begin(), it);
	sortedArr.sort();
	//printList2(sortedArr);
	for (int i = 3; i < n; i += 2)
	{
		it = list.begin();
		increment(it, i);
		int a = *it;
		//std::cout << "a = " << a << std::endl;
		int b = INT_MAX;
		if (i + 1 < n)
		{
			it = list.begin();
			increment(it, i + 1);
			b = *it;
		}
		//std::cout << "b = " << b << std::endl;
		if (a > b) std::swap(a, b);

		binaryInsertList(sortedArr, sortedArr.size(), a);

		if (b != INT_MAX)
			binaryInsertList(sortedArr, sortedArr.size(), b);
	}
	//printList2(list);
	//printList2(sortedArr);
	std::copy(sortedArr.begin(), sortedArr.end(), list.begin());
}

void	PmergeMe::binaryInsertList(List& list, int sortedEnd, int key)
{
	int left = 0, right = sortedEnd - 1;
	while (left <= right)
	{
		Iterator midIt = list.begin();
		int mid = left + (right - left) / 2;
		//std::cout << "left = " << left << std::endl;
		//std::cout << "right = " << right << std::endl;
		//std::cout << "mid = " << mid << std::endl;
		increment(midIt, mid);
		if (*midIt == key)
		{
			Iterator it = list.begin();
			increment(it, mid + 1);
			list.insert(it, key);
			return;
		}
		if (*midIt < key)
			left = mid + 1;
		else
			right = mid - 1;
	}
	Iterator it = list.begin();
	increment(it, left);
	list.insert(it, key);
}
