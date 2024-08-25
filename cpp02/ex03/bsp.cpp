/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:24:06 by melachyr          #+#    #+#             */
/*   Updated: 2024/08/25 22:53:54 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.hpp"

Fixed	getTriangleSurface(Point const a, Point const b, Point const c)
{
	Fixed	r1 = a.getX() * (b.getY() - c.getY());
	Fixed	r2 = b.getX() * (c.getY() - a.getY());
	Fixed	r3 = c.getX() * (a.getY() - b.getY());
	Fixed	surface = (r1 + r2 + r3) / 2;
	if (surface < 0) 
		surface = surface * -1;
	return (surface);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	abcSurface = getTriangleSurface(a, b, c);
	Fixed	pabSurface = getTriangleSurface(point, a, b);
	Fixed	pacSurface = getTriangleSurface(point, a, c);
	Fixed	pbcSurface = getTriangleSurface(point, b, c);

	Fixed	sum = pabSurface + pacSurface + pbcSurface;
	return (abcSurface == sum);
}
