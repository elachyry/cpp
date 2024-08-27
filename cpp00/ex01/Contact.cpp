/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 20:46:33 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/27 15:16:43 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void)
{
	this->firstName = "";
	this->lastName = "";
	this->nickName = "";
	this->phoneNumber = "";
	this->darkestSecret = "";
}

void	Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;
	return ;
}

void	Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
	return ;
}

void	Contact::setNickName(std::string nickName)
{
	this->nickName = nickName;
	return ;
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
	return ;
}

void	Contact::setDarkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
	return ;
}

std::string Contact::getFirstName(void)
{
	return (this->firstName);
}

std::string Contact::getLastName(void)
{
	return (this->lastName);
}

std::string Contact::getNickName(void)
{
	return (this->nickName);
}

std::string Contact::getPhoneNumber(void)
{
	return (this->phoneNumber);
}

std::string Contact::getDarkestSecret(void)
{
	return (this->darkestSecret);
}
