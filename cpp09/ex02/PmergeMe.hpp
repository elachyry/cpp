/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:33:01 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/20 00:40:34 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <bits/stdc++.h> 
# include <iomanip>

typedef std::vector<int> Vector;
typedef std::list<int> List;
typedef std::list<int>::iterator Iterator;
// typedef std::chrono::high_resolution_clock::time_point Time;

class	PmergeMe
{
	public:
		PmergeMe( void );
		PmergeMe( const PmergeMe& );
		~PmergeMe( void );
		PmergeMe&	operator = ( const PmergeMe& );
		void		mergeSortVector( Vector& );
		List		mergeSortList( List );
};

#endif