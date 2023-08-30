/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmasetti <lmasetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:47:15 by lmasetti          #+#    #+#             */
/*   Updated: 2023/08/30 11:47:15 by lmasetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Fixed x, const Fixed y) : x(x), y(y) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other)
{
    if (this != &other) {
        // Since x and y are const, we don't need to reassign them.
    }
    return *this;
}

Point::~Point() {}

const Fixed Point::getX() const {
    return x;
}

const Fixed Point::getY() const {
    return y;
}