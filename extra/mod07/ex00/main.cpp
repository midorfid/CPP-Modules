#include "whatever.hpp"
#include <iostream>

int main(void) {
{
    int a = 2;
    int b = 3;

    swap(a, b);
    std::cout << "a: " << a << ", b: " << b << '\n';
    std::cout << "min: " << myMin(a,b) << '\n'; 
    std::cout << "max: " << myMax(a,b) << '\n'; 
}
    std::string a = "chained1";
    std::string b = "chained2";

    swap(a,b);
    std::cout << "a: " << a << ", b: " << b << '\n';
    std::cout << "min: " << myMin(a,b) << '\n'; 
    std::cout << "max: " << myMax(a,b) << '\n'; 

}