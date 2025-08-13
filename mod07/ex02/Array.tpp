#include "Array.hpp"
#include <algorithm>
#include <iostream>

template<typename T>
Array<T>::Array() : _size(0), _arr(new T[0]) {
    return;
}

template<typename T>
Array<T>::~Array() {
    delete [] this->_arr;
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n) {
    this->_arr = new T[n];
}

template<typename T>
Array<T>::Array(const Array<T> &other) : _size(other._size), _arr(new T(*other._arr)) {
}

template<typename T>
Array<T> &Array<T>::operator=(Array<T> other) {
    std::swap(this, &other);
    return *this;
}

template<typename T>
T &Array<T>::operator[](unsigned int i) {
    if (i >= this->_size)
        throw std::out_of_range("out of range");
    return this->_arr[i];
}

template<typename T>
const unsigned int&Array<T>::size() const {
    return this->_size;
}
