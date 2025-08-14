#pragma once

template <typename T>
class Span {
    protected:
        Span();

    private:
        unsigned int    _size;
        unsigned int    _capacity;
        T               *_arr;

    public:
        typedef T* iterator;

        ~Span();

        Span(const Span &other);

        Span &operator=(Span other);

        T   &operator[](unsigned int i);

        Span(unsigned int N);

        void            addNumber(T toAdd);

        template <typename InputIterator>
        void            addNumber(InputIterator first, InputIterator last);

        iterator        begin() const;

        iterator        end() const;

        int             shortestSpan() const;

        int             longestSpan() const;

    };

#include "Span.tpp"
