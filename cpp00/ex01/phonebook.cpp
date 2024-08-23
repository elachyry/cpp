/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 20:31:02 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/23 17:23:40 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	this->currenIndex = 0;
	for (int i = 0; i < 8; i++)
	{
		this->contacts[i] = Contact();
	}
}

int	PhoneBook::getCurrentIndex(void)
{
	return (this->currenIndex);
}

void	PhoneBook::add(Contact contact)
{
	this->contacts[this->currenIndex] = contact;
	this->currenIndex = (this->currenIndex + 1) % 8;
	return ;
}

Contact	PhoneBook::search(int index)
{
	return (this->contacts[index]);
}
