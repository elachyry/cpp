/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:32:46 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/20 00:31:44 by melachyr         ###   ########.fr       */
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

void	mergeVector(Vector& vector, Vector& leftVect, Vector& rightVect)
{
	int	leftSize = vector.size() / 2;
	int	rightSize = vector.size() - leftSize;

	int	i = 0;
	int	left = 0;
	int	right = 0;

	while (left < leftSize && right < rightSize)
	{
		if (leftVect[left] < rightVect[right])
		{
			vector[i] = leftVect[left];
			left++;
			i++;
		}
		else
		{
			vector[i] = rightVect[right];
			right++;
			i++;
		}
	}
	while (left < leftSize)
	{
		vector[i] = leftVect[left];
		left++;
		i++;
	}
	while (right < leftSize)
	{
		vector[i] = rightVect[right];
		right++;
		i++;
	}
}

void	PmergeMe::mergeSortVector(Vector& vector)
{
	int	length = vector.size();
	if (length < 2)
		return ;

	int	middle = length / 2;
	Vector leftVector(middle);
	Vector rightVector(length - middle);

	int i = 0, j = 0;
	while (i < length)
	{
		if (i < middle)
			leftVector[i] = vector[i];
		else
		{
			rightVector[j] = vector[i];
			j++;
		}
		i++;
	}
	mergeSortVector(leftVector);
	mergeSortVector(rightVector);
	mergeVector(vector, leftVector, rightVector);
}

void	printList2(List& list)
{
	Iterator start = list.begin();
	Iterator end = list.end();

	for (Iterator it = start; it != end; it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

List	mergeList(List& leftList, List& rightList)
{
	List result;

	Iterator left = leftList.begin();
	Iterator right = rightList.begin();

	while (left != leftList.end() && right != rightList.end())
	{
		if (*left < *right)
		{
			result.push_back(*left);
			left++;
		}
		else
		{
			result.push_back(*right);
			right++;
		}
	}
	result.insert(result.end(), left, leftList.end());
	result.insert(result.end(), right, rightList.end());
	return (result);

}

List	PmergeMe::mergeSortList(List list)
{
	int	length = list.size();
	if (length < 2)
		return (list);

	List leftList;
	List rightList;
	Iterator middle = list.begin();
	std::advance(middle, length / 2);

	leftList.splice(leftList.begin(), list, list.begin(), middle);
	rightList.splice(rightList.begin(), list, middle, list.end());

	List left = mergeSortList(leftList);
	List right = mergeSortList(rightList);
	List result = mergeList(left, right);
	return (result);
}
