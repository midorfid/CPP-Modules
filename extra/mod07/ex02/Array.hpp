#pragma once

#include <stdexcept>

template <typename T>
class Array {
    public:
        Array();
        ~Array();

        Array(unsigned int n);

        Array(const Array &other);

        Array &operator=(Array other);

        T &operator[](unsigned int i);

        const unsigned int  &size() const;
	private:
		unsigned int	_size;
		T				*_arr;
};

#include "Array.tpp"
