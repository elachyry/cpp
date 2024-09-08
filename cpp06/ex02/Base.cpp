/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:25:17 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/08 23:48:15 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

//check for c cast!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

Base::~Base( void ) {}

Base	*generate( void )
{
	std::srand(std::time(0));
	int result = std::rand() % 3;
	std::cout << "result " << result << std::endl;
	Base *base = NULL;
	switch (result)
	{
	case 0:
		base = new A();
		break;
	case 1:
		base = new B();
		break;
	case 2:
		base = new C();
		break;
	}
	return (base);
}

void	identify(Base* base)
{
	if (dynamic_cast<A*>(base))
		std::cout << "Pointer identify is A." << std::endl;
	else if (dynamic_cast<B*>(base))
		std::cout << "Pointer identify is B." << std::endl;
	else if (dynamic_cast<C*>(base))
		std::cout << "Pointer identify is C." << std::endl;
	else
		std::cout << "Pointer identify is unknown." << std::endl;
}

void	identify(Base& base)
{
	A	a;
	B	b;
	C	c;
	try
	{
		a = dynamic_cast<A&>(base);
		(void)a;
		std::cout << "Pointer identify is A." << std::endl;
		return ;
	}
	catch(std::exception& e) {}

	try
	{
		b = dynamic_cast<B&>(base);
		(void)b;
		std::cout << "Pointer identify is B." << std::endl;
		return ;
	}
	catch(std::exception& e) {}

	try
	{
		c = dynamic_cast<C&>(base);
		std::cout << "Pointer identify is C." << std::endl;
		return ;
	}
	catch(std::exception& e)
	{
		std::cout << "Pointer identify is unknown." << std::endl;
	}
}
