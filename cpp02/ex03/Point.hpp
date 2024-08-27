/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:48:23 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/27 15:34:57 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	const Fixed	x;
	const Fixed	y;

public:
	Point( void );
	Point( const Fixed x, const Fixed y );
	Point( const Point& point );
	Point&	operator = (const Point& point);
	~Point();
	const Fixed	getX( void ) const;
	const Fixed	getY( void ) const;
	
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);


#endif