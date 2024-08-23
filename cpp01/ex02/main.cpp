/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:11:44 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/23 15:30:41 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main( void )
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "The memory address of the str = " << &str << std::endl;
    std::cout << "The memory address held by stringPTR = " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF = " << &stringREF << std::endl;

    std::cout << "The value of the str = " << str << std::endl;
    std::cout << "The value pointed to by stringPTR = " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF = " << stringREF << std::endl;
    return (0);
}
