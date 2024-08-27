/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:47:15 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/27 15:35:30 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : x(0), y(0) {}

Point::Point( const Fixed x, const Fixed y ) : x(x), y(y) {}

Point::Point( const Point& point ) : x(point.x), y(point.y) {}

Point&	Point::operator = ( const Point& point )
{
	(void) point;
	return (*this);
}

Point::~Point() {}

const Fixed	Point::getX( void ) const 
{
	return (this->x);
}

const Fixed	Point::getY( void )const
{
	return (this->y);
}
