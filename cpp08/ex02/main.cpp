/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:36:34 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/20 20:07:23 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main( void )
{
	MutantStack<double> myStack;

	myStack.push(5.5);
	myStack.push(6.2);
	myStack.push(7);
	myStack.push(8);
	myStack.push(9);

	MutantStack<double> myStack2(myStack);
	
	MutantStack<double>::iterator it = myStack2.begin();
	MutantStack<double>::iterator ite = myStack2.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	return (0);
}
