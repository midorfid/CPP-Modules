#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <exception>
#include <iterator>
#include <cstring>
#include <climits>
#include <vector>

template <typename T>
Span<T>::Span() :  _size(0), _capacity(0), _arr(new T[0]) {
    std::cout << "span const" << '\n';
}

template <typename T>
Span<T>::~Span() {
    delete [] this->_arr;
}

template <typename T>
Span<T>::Span(const Span<T> &other) : _size(other._size), _capacity(other._capacity), _arr(new T[other._capacity]) {
    std::cout << "span copy const" << '\n';
    int size = static_cast<int>(_size);
    for (int i = 0; i < size; ++i) {
        _arr[i] = other._arr[i];
    }
}

template <typename T>
Span<T> &Span<T>::operator=(Span<T> other) {
    if (this != &other)
        std::swap(*this, other);

    return *this;
}

template <typename T>
T   &Span<T>::operator[](unsigned int i) {
    if (i >= this->_size)
        throw std::out_of_range("out of range");
    return this->_arr[i];
}

template <typename T>
Span<T>::Span(unsigned int N) : _size(0), _capacity(N), _arr(new T[N]) {
    std::cout << "span size const" << '\n';
}

template <typename T>
void Span<T>::addNumber(T toAdd) {
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
        throw std::logic_error("not enough elements");
    std::vector<T> span_cpy(this->begin(), this->end());
    
	std::sort(span_cpy.begin(), span_cpy.end());

	int shortest = INT_MAX;
	int size = static_cast<int>(_size);
    for (int i = 0; i < size - 1; ++i) {
		int currentShortest = span_cpy[i + 1] - span_cpy[i];
		shortest = std::min(currentShortest, shortest);
	}

	return shortest;
}

template <typename T>
int Span<T>::longestSpan() const {
    if (_size < 2)
    throw std::logic_error("not enough elements");
    std::vector<T> span_cpy(this->begin(), this->end());

	std::sort(span_cpy.begin(), span_cpy.end());

	return span_cpy[_size - 1] - span_cpy[0];
}

template <typename T>
template <typename InputIterator>
void    Span<T>::addNumber(InputIterator first, InputIterator last) {
    unsigned int dist = std::distance(first, last);
    if (dist > _capacity - _size)
        throw std::out_of_range("out_of_range");

    std::copy(first, last, &_arr[_size]);
    _size += dist;
}
