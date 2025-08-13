#pragma once

template <typename T>
void   swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T   myMin(T a, T b) {
    return a < b ? a : b;
}

template <typename T>
T   myMax(T a, T b) {
    return a > b ? a : b;
}
