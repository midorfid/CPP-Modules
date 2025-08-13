#include "easyfind.hpp"
#include <exception>

int main(void) {
    std::vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    try {
        easyfind(v, 5);
    } catch(int) {
        std::cout << "not found" << std::endl;
    }
}
