#pragma once
#include <algorithm>
#include <vector>
#include <iostream>

template <typename T>
void easyfind(const T &container, const int &toFind) {
    if (std::find(container.begin(), container.end(), toFind) == container.end())
        throw 1;
    std::cout << "found" << '\n';
    return;
}
