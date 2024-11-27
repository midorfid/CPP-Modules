#include "Point.hpp"
#include "bsp.cpp"

int main(void) {

    Point const a((float)0.0, (float)0.0);
    Point const b((float)4.5, (float)0.0);
    Point const c((float)2.2, (float)3.8);
    Point const point((float)2.2, (float)3.799);
    
    
    if (bsp(a, b, c, point) == true)
        std::cout << "inside triangle" << std::endl;
    else
        std::cout << "outside triangle" << std::endl;

    return (0);
}