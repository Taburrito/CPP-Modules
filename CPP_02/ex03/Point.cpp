/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:45 by awaegaer          #+#    #+#             */
/*   Updated: 2026/01/28 11:50:19 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	value_calc(Point const a, Point const b, Point const p)
{
	Fixed	res((p.getPointX() - a.getPointX()) * (b.getPointY() - a.getPointY()) - (p.getPointY() - a.getPointY()) * (b.getPointX() - a.getPointX()));
	return (res);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	int c1, c2, c3;
	c1 = value_calc(a, b, point).toInt();
	c2 = value_calc(b, c, point).toInt();
	c3 = value_calc(c, a, point).toInt();
	if (c1 > 0 && c2 > 0 && c3 > 0)
		return (true);
	else if (c1 < 0 && c2 < 0 && c3 < 0)
		return (true);
	return (false);
}


// ************************************************************************** //
//                           Const/Dest/Copy/Assign                           //
// ************************************************************************** //

Point::Point(void)
{
	return;
}

Point::Point(const float fx, const float fy) : x(fx), y(fy)
{
	return;
}

Point::~Point(void)
{
	return;
}

Point::Point(const Point &src) : x(src.x), y(src.y)
{
	return;
}

Point	&Point::operator=(const Point &rhs)
{
	(void)rhs;
	return (*this);
}

// ************************************************************************** //
//                                 Gets/Sets                                  //
// ************************************************************************** //


Fixed	Point::getPointX(void) const
{
	return (this->x);
}

Fixed	Point::getPointY(void) const
{
	return (this->y);
}
