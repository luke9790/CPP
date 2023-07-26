#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    // Calculate vectors
    Point ab(b.getX() - a.getX(), b.getY() - a.getY());
    Point bc(c.getX() - b.getX(), c.getY() - b.getY());
    Point ca(a.getX() - c.getX(), a.getY() - c.getY());
    Point ap(point.getX() - a.getX(), point.getY() - a.getY());
    Point bp(point.getX() - b.getX(), point.getY() - b.getY());
    Point cp(point.getX() - c.getX(), point.getY() - c.getY());

    // Calculate cross products
    Fixed crossAB = (ab.getX() * ap.getY()) - (ab.getY() * ap.getX());
    Fixed crossBC = (bc.getX() * bp.getY()) - (bc.getY() * bp.getX());
    Fixed crossCA = (ca.getX() * cp.getY()) - (ca.getY() * cp.getX());

    // Check if the point is inside the triangle
    return (crossAB >= 0 && crossBC >= 0 && crossCA >= 0) ||
           (crossAB <= 0 && crossBC <= 0 && crossCA <= 0);
}