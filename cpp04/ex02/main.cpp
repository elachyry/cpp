/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:39:45 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/31 21:49:51 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}

	std::cout << std::endl << "******************************************" << std::endl;

	{
		AAnimal* animals[10];
		for (int i = 0; i < 5; i++)
		{
			animals[i] = new Dog();
		}
		for (int i = 5; i < 10; i++)
		{
			animals[i] = new Cat();
		}
		for (int i = 0; i < 10; i++)
		{
			delete animals[i];
		}
	}
	
	return 0;
}