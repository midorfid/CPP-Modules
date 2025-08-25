#pragma once
#include <iostream>

template <typename T>
void iter(T *ptr, size_t len, void (*f)(const T& element)) {
    int upperbound = static_cast<int>(len);
    for (int i = 0; i < upperbound; ++i) {
        f(ptr[i]);
    }
}

template <typename T>
void printElement(const T &element) {
    std::cout << element << ' ';
}
