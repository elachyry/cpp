/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:33:01 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/30 22:23:46 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <vector>
# include <deque>
# include <utility>
# include <bits/stdc++.h> 
# include <iomanip>

typedef std::vector<int>					Vector;
typedef std::vector<std::pair<int, int> >	PairVector;
typedef std::deque<int>						Deque;
typedef std::deque<std::pair<int, int> >	PairDeque;

class	PmergeMe
{
	public:
		PmergeMe( void );
		PmergeMe( const PmergeMe& );
		~PmergeMe( void );
		PmergeMe&	operator = ( const PmergeMe& );
		void	fordJohnsonSortVector( Vector& );
		void	binaryInsertVector( Vector&, int, int );
		void	fordJohnsonSortDeque( Deque& );
		void	binaryInsertDeque(Deque&, int, int );
};

#endif