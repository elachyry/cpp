/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:32:46 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/30 22:23:00 by melachyr         ###   ########.fr       */
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
	if (this != &pmergeMe) {}
	return (*this);
}

Vector generateJacobsthalSequence(int n)
{
	Vector jacobsthal;
	Vector jacobsthalFinal;

	jacobsthal.push_back(0);
	if (n > 1) jacobsthal.push_back(1);
	for (int i = 2; jacobsthal.size() > 1 && jacobsthal.back() < n; ++i)
	{
		jacobsthal.push_back(jacobsthal[i - 1] + 2 * jacobsthal[i - 2]);
	}
	for (size_t i = 1; i < jacobsthal.size(); i++)
	{
		for (int j = jacobsthal[i]; j > jacobsthal[i - 1] ; j--)
			jacobsthalFinal.push_back(j - 1);
	}
	return (jacobsthalFinal);
}

void	mergeVector(PairVector& vector, PairVector& leftVect, PairVector& rightVect)
{
	int	leftSize = vector.size() / 2;
	int	rightSize = vector.size() - leftSize;

	int	i = 0;
	int	left = 0;
	int	right = 0;

	while (left < leftSize && right < rightSize)
	{
		if (leftVect[left].first < rightVect[right].first)
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
	while (right < rightSize)
	{
		vector[i] = rightVect[right];
		right++;
		i++;
	}
}

void	mergeSortVector(PairVector& vector)
{
	int	length = vector.size();
	if (length < 2)
		return ;

	int	middle = length / 2;
	PairVector leftVector(middle);
	PairVector rightVector(length - middle);

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

void	PmergeMe::fordJohnsonSortVector(Vector& vector)
{
	PairVector	pairVect;
	Vector		largest;
	Vector		lowest;
	int			size = vector.size();
	
	for (int i = 0; i < size; i += 2)
	{
		int	a = vector[i];
		int	b = (i + 1 < size) ? vector[i + 1] : -1;
		if (a < b) std::swap(a, b);
		pairVect.push_back(std::pair<int, int>(a, b));
	}
	mergeSortVector(pairVect);
	for (size_t i = 0; i < pairVect.size(); i++)
	{
		largest.push_back(pairVect[i].first);
		lowest.push_back(pairVect[i].second);
	}
	Vector extededJacobSequ = generateJacobsthalSequence(lowest.size());
	if (lowest[0] != -1)
		largest.insert(largest.begin(), lowest[0]);
	for (size_t i = 1; i < extededJacobSequ.size(); i++)
	{
		size_t	currentIndex = extededJacobSequ[i];
		if (currentIndex >= lowest.size())
			continue ;
		if (lowest[currentIndex] != -1)
			binaryInsertVector(largest, largest.size(), lowest[currentIndex]);
	}
	std::copy(largest.begin(), largest.end(), vector.begin());
}

void	PmergeMe::binaryInsertVector(Vector& vector, int sortedEnd, int key)
{
	int left = 0, right = sortedEnd - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (vector[mid] == key)
		{
			vector.insert(vector.begin() + mid + 1, key);
			return;
		}
		if (vector[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;
	}
	vector.insert(vector.begin() + left, key);
}

void	mergeDeque(PairDeque& deque, PairDeque& leftVect, PairDeque& rightVect)
{
	int	leftSize = deque.size() / 2;
	int	rightSize = deque.size() - leftSize;

	int	i = 0;
	int	left = 0;
	int	right = 0;

	while (left < leftSize && right < rightSize)
	{
		if (leftVect[left].first < rightVect[right].first)
		{
			deque[i] = leftVect[left];
			left++;
			i++;
		}
		else
		{
			deque[i] = rightVect[right];
			right++;
			i++;
		}
	}
	while (left < leftSize)
	{
		deque[i] = leftVect[left];
		left++;
		i++;
	}
	while (right < rightSize)
	{
		deque[i] = rightVect[right];
		right++;
		i++;
	}
}

void	mergeSortDeque(PairDeque& deque)
{
	int	length = deque.size();
	if (length < 2)
		return ;

	int	middle = length / 2;
	PairDeque leftDeque(middle);
	PairDeque rightDeque(length - middle);

	int i = 0, j = 0;
	while (i < length)
	{
		if (i < middle)
			leftDeque[i] = deque[i];
		else
		{
			rightDeque[j] = deque[i];
			j++;
		}
		i++;
	}
	mergeSortDeque(leftDeque);
	mergeSortDeque(rightDeque);
	mergeDeque(deque, leftDeque, rightDeque);
}

void	PmergeMe::fordJohnsonSortDeque(Deque& deque)
{
	PairDeque	pairDeq;
	Deque		largest;
	Deque		lowest;
	int			size = deque.size();
	
	for (int i = 0; i < size; i += 2)
	{
		int	a = deque[i];
		int	b = (i + 1 < size) ? deque[i + 1] : -1;
		if (a < b) std::swap(a, b);
		pairDeq.push_back(std::pair<int, int>(a, b));
	}
	mergeSortDeque(pairDeq);
	for (size_t i = 0; i < pairDeq.size(); i++)
	{
		largest.push_back(pairDeq[i].first);
		lowest.push_back(pairDeq[i].second);
	}
	Vector extededJacobSequ = generateJacobsthalSequence(lowest.size());
	if (lowest[0] != -1)
		largest.insert(largest.begin(), lowest[0]);
	for (size_t i = 1; i < extededJacobSequ.size(); i++)
	{
		size_t	currentIndex = extededJacobSequ[i];
		if (currentIndex >= lowest.size())
			continue ;
		if (lowest[currentIndex] != -1)
			binaryInsertDeque(largest, largest.size(), lowest[currentIndex]);
	}
	std::copy(largest.begin(), largest.end(), deque.begin());
}

void	PmergeMe::binaryInsertDeque(Deque& deque, int sortedEnd, int key)
{
	int left = 0, right = sortedEnd - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (deque[mid] == key)
		{
			deque.insert(deque.begin() + mid + 1, key);
			return;
		}
		if (deque[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;
	}
	deque.insert(deque.begin() + left, key);
}
