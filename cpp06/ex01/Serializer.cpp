/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:18:20 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/14 00:30:58 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"

Serializer::Serializer( void ) {}

Serializer::Serializer(const Serializer& serializer)
{
	*this = serializer;
}

Serializer::~Serializer( void ) {}

Serializer&	Serializer::operator = (const Serializer& serializer)
{
	if (this != &serializer) {}
	return (*this);
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	if (!ptr)
		return (0);
	uintptr_t dataToWrite = reinterpret_cast<uintptr_t>(ptr);
	std::cout << "Object serialized successfully." << std::endl;
	return (dataToWrite);
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	if (!raw)
		return (NULL);
	Data *data = reinterpret_cast<Data *>(raw);
	std::cout << "Object desserialized successfully." << std::endl;
	return (data);
}

