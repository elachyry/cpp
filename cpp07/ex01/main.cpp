/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:36:34 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/16 17:50:33 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// class	Awesome
// {
// 	public:
// 		Awesome( void ) : _n( 42 ) { return; }
// 		int get( void ) const { return this->_n; }

// 	private:
// 		int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
// 	o << rhs.get();
// 	return o;
// }

template< typename T >
void print( T& x )
{
	std::cout << x << std::endl;
	return;
}

template< typename T >
void incriment( T& x )
{
	++x;
}

int main() {
	int tab[] = { 0, 1, 2, 3, 4 };
	iter( tab, 5, print<const int> );
	iter( tab, 5, incriment<int> );

	
	// Awesome tab2[5];

	// iter( tab, 5, print<const int> );
	// iter( tab2, 5, print<Awesome> );

	return 0;
}
