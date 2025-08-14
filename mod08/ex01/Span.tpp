#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <exception>


template <typename T>
Span<T>::Span() :  _size(0), _capacity(0), _arr(new T[0]) {
    std::cout << "span const" << '\n';
}

template <typename T>
Span<T>::~Span() {
    delete [] this->_arr;
}

template <typename T>
Span<T>::Span(const Span<T> &other) : _size(other._size), _capacity(other._capacity), _arr(new T(other._capacity)) {
    std::cout << "span copy const" << '\n';
    int size = static_cast<int>(_size);
    for (int i = 0; i < size; ++i) {
        _arr[i] = other._arr[i];
    }

}

template <typename T>
Span<T> &Span<T>::operator=(Span<T> other) {
    if (this != &other)
        std::swap(this, &other);

    return *this;
}

template <typename T>
T   &Span<T>::operator[](unsigned int i) {
    if (i >= this->_size)
        throw std::out_of_range("out of range");
    return this->_arr[i];
}

template <typename T>
Span<T>::Span(unsigned int &N) : _size(0), _capacity(N), _arr(new T[N]) {
    std::cout << "span size const" << '\n';
}

template <typename T>
void Span<T>::addNumber(const T &toAdd) {
    if (_size == _capacity)
        throw std::logic_error("container is full");
    _arr[_size] = toAdd;
    ++_size;
}

template <typename T>
typename Span<T>::iterator Span<T>::begin() const {
	return this->_arr;
}

template <typename T>
typename Span<T>::iterator Span<T>::end() const {
	return this->_arr + _size;
}

template <typename T>
int Span<T>::shortestSpan() const {
    if (_size < 2)
        throw std::logic_error("container is full");
    Span<T> span_cpy = *this;

	std::sort(span_cpy.begin(), span_cpy.end());

	int shortest = __INT_MAX__;
	int size = static_cast<int>(_size);
    for (int i = 0; i < size - 1; ++i) {
		int currentShortest = span_cpy._arr[i + 1] - span_cpy._arr[i];
		shortest = currentShortest < shortest ? currentShortest : shortest; 
	}
	return shortest;
}

template <typename T>
int Span<T>::longestSpan() const {
    if (_size < 2)
    throw std::logic_error("container is full");
    Span<T> span_cpy = *this;

	std::sort(span_cpy.begin(), span_cpy.end());

	return span_cpy[_size - 1] - span_cpy[0];
}
