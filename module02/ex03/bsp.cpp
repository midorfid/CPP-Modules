#include "Point.hpp"
/* result < 0 - the point is in the back region of the line
   result == 0 - point is on the line
   result > 0 - point is in front of the */
bool calculateCP(Point const p1, Point const p2, Point const tofind) {
    Fixed res;
    //vector of the P1P2
    Point D(p2 - p1);
    //vector P1tofind
    Point V(tofind - p1);
    //Cross product Dx * Vy - Dy * Vx
    res = D.getX() * V.getY() - D.getY() * V.getX();
    if (res <= 0) { return false;}
    return true;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // basic bsp tree simulation hardcoded
    if (calculateCP(a, b, point) == true) {
        if (calculateCP(b, c, point) == true) {
            if (calculateCP(c, a, point) == true)
                return true;
                else { return false; }
        }
        else { return false; }
    }
    else { return false; }
}