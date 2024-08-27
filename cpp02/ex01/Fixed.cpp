/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:40:30 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/27 15:31:40 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}

Fixed::Fixed( const Fixed& fixed )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->fixedPoint = fixed.fixedPoint;
	return *this;
}

Fixed::Fixed( const int number )
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = number * (1 << fraction);
}

Fixed::Fixed( const float number )
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPoint = roundf(number * (1 << fraction));
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPoint);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPoint = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)this->fixedPoint / (1 << fraction));
}

int	Fixed::toInt( void ) const
{
	return (this->fixedPoint / (1 << fraction));
}

std::ostream&	operator << (std::ostream& output, const Fixed& fixed)
{
	output << fixed.toFloat();
	return (output);
}
