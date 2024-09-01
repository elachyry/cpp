/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:40:30 by melachyr          #+#    #+#             */
/*   Updated: 2024/09/01 13:59:10 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int	Fixed::fraction = 8;

Fixed::Fixed( void )
{
	// std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}

Fixed::Fixed( const Fixed& fixed )
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed& Fixed::operator = (const Fixed& fixed)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->fixedPoint = fixed.fixedPoint;
	return *this;
}

Fixed::Fixed( const int number )
{
	// std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = number * (1 << fraction);
}

Fixed::Fixed( const float number )
{
	// std::cout << "Float constructor called" << std::endl;
	this->fixedPoint = roundf(number * (1 << fraction));
}

Fixed::~Fixed( void )
{
	// std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPoint);
}

void	Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;
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

bool	Fixed::operator < (const Fixed& fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator <= (const Fixed& fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator > (const Fixed& fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator >= (const Fixed& fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator == (const Fixed& fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator != (const Fixed& fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

Fixed	Fixed::operator + (const Fixed& fixed) const
{
	Fixed	result;
	result.setRawBits(this->getRawBits() + fixed.getRawBits());
	return (result);
}

Fixed	Fixed::operator - (const Fixed& fixed) const
{
	Fixed	result;
	result.setRawBits(this->getRawBits() - fixed.getRawBits());
	return (result);
}

Fixed	Fixed::operator * (const Fixed& fixed) const
{
	Fixed	result;
	result.setRawBits(this->getRawBits() * (fixed.getRawBits()) / (1 << fraction));
	return (result);
}

Fixed	Fixed::operator / (const Fixed& fixed) const
{
	Fixed	result;
	result.setRawBits(this->getRawBits() / (fixed.getRawBits()) * (1 << fraction));
	return (result);
}

Fixed&	Fixed::operator ++ ( void )
{
	this->fixedPoint += 1;
	return (*this);
}

Fixed&	Fixed::operator -- ( void )
{
	this->fixedPoint -= 1;
	return (*this);
}

Fixed	Fixed::operator ++ ( int )
{
	Fixed	tmp = *this;
	this->fixedPoint += 1;
	return (tmp);
}

Fixed	Fixed::operator -- ( int )
{
	Fixed	tmp = *this;
	this->fixedPoint -= 1;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1 < fixed2 ? fixed1 : fixed2);
}

const Fixed	&Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1 > fixed2 ? fixed1 : fixed2);
}

const Fixed	&Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1 < fixed2 ? fixed1 : fixed2);
}

Fixed	&Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1 > fixed2 ? fixed1 : fixed2);
}
