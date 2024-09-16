/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:36:34 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/15 22:09:05 by melachyr         ###   ########.fr       */
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

	try
	{
		// std::cout << myStack.top() << std::endl;
		// myStack.pop();
		// std::cout << myStack.top() << std::endl;
		// std::cout << "size " << myStack.size() << std::endl;
		// std::cout << "dsfsd" << std::endl;
		// myStack.pop();
		// std::cout << myStack.top() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	MutantStack<double>::iterator it = myStack.begin();
	MutantStack<double>::iterator ite = myStack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	return (0);
}
