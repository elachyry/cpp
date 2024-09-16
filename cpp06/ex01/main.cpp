/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:45:48 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/14 00:32:44 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data *d1 = new Data("Mohammed", 20, 'F', 20000.25);

	std::cout << "***************Before Serialization***************" << std::endl;
	std::cout << "Name: " << d1->getName() << std::endl;
	std::cout << "Age: " << d1->getAge() << std::endl;
	std::cout << "Gender: " << d1->getGender() << std::endl;
	std::cout << "Bank Balance: " << d1->getAccountBalance() << std::endl;

    uintptr_t result = Serializer::serialize(d1);
	
    Data *d2 = Serializer::deserialize(result);
	
	std::cout << "***************After Serialization***************" << std::endl;
	if (!d2)
		return (0);
	std::cout << "Name: " << d2->getName() << std::endl;
	std::cout << "Age: " << d2->getAge() << std::endl;
	std::cout << "Gender: " << d2->getGender() << std::endl;
	std::cout << "Bank Balance: " << d2->getAccountBalance() << std::endl;

	delete d1;
    return (0);
}
