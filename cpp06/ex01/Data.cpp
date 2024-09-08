/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:23:41 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/08 21:51:02 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Data.hpp"

Data::Data( void )
{
	this->name = "Mohammed";
	this->age = 23;
	this->gender = 'M';
	this->bankAccount = 0;
}

Data::Data( std::string name, int age, char gender, double bankAccount )
{
	this->name = name;
	this->age = age;
	this->gender = gender;
	this->bankAccount = bankAccount;
}

Data::Data(const Data& data)
{
	*this = data;
}

Data::~Data( void ) {}

Data&	Data::operator = (const Data& data)
{
	if (this != &data)
	{
		this->name = data.name;
		this->age = data.age;
		this->gender = data.gender;
		this->bankAccount = data.bankAccount;
	}
	return (*this);
}

std::string	Data::getName( void )
{
	return (this->name);
}

int			Data::getAge( void )
{
	return (this->age);
}

char		Data::getGender( void )
{
	return (this->gender);
}

double		Data::getAccountBalance( void )
{
	return (this->bankAccount);
}

