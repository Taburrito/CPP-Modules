/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awaegaer <awaegaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:55:49 by awaegaer          #+#    #+#             */
/*   Updated: 2026/02/09 14:19:05 by awaegaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_H__
#define __POINT_H__

# include "Fixed.hpp"

// ************************************************************************** //
//                               Point Class                                  //
// ************************************************************************** //

class Point
{

public:
	Point(void);
	Point(const float fx, const float fy);
	~Point(void);
	Point(const Point &other);
	Point &operator=(const Point &rhs);

	Fixed	getPointX(void) const;
	Fixed	getPointY(void) const;

private:
	Fixed const	x;
	Fixed const	y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
