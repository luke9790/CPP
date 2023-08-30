/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:47:19 by lmasetti          #+#    #+#             */
/*   Updated: 2023/08/30 11:47:19 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;

public:
	Point();
	Point(const Fixed x, const Fixed y);
	Point(const Point& copy);
	Point& operator=(const Point& assign);	
	~Point();

	const Fixed getX() const;
    const Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
