/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:45:48 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/13 18:36:31 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	Base *base1 = generate();
	Base *base2 = generate();
	
	identify(base1);
	identify(*base2);
	
	delete base1;
	delete base2;
    return (0);
}
