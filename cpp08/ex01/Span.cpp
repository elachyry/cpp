/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:06:39 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/26 14:59:29 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ) : N(0) {}

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span& span)
{
	*this = span;
}

Span::~Span( void ) {}

Span&	Span::operator = ( const Span& span )
{
	if (this != &span)
	{
		this->N = span.N;
		this->data = span.data;
	}
	return (*this);
}

void	Span::addNumber(int n)
{
	if (data.size() == N)
		throw std::out_of_range("Exception: Span is full!");
	data.push_back(n);
}

int	Span::shortestSpan( void )
{
	if (data.size() < 2)
		throw std::logic_error("Exception: Not enough numbers!");
		
	std::sort(data.begin(),data.end());
	int min = data[1] - data[0];
	for (size_t i = 1; i < data.size() - 1; i++)
	{
		int result = data[i + 1] - data[i];
		if (result < min)
			min = result;
	}
	return (min);
}

int	Span::longestSpan( void )
{
	if (data.size() < 2)
		throw std::logic_error("Exception: Not enough numbers!");
		
	int	max = *std::max_element(data.begin(), data.end());
	int	min = *std::min_element(data.begin(), data.end());
	return (max - min);
}
