#include <iostream>
#include "Point.hpp"

int main()
{
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);

    Point inside(2.5f, 2.5f);
    Point outside(4.0f, 3.0f);

    if (bsp(a, b, c, inside))
        std::cout << "The point inside is inside the triangle.\n";
    else
        std::cout << "The point inside is outside the triangle.\n";

    if (bsp(a, b, c, outside))
        std::cout << "The point outside is inside the triangle.\n";
    else
        std::cout << "The point outside is outside the triangle.\n";

    return 0;
}