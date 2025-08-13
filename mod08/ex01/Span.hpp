#pragma once

template <typename T>
class Span {
    private:
        unsigned int    _size;
        T               *_arr;

    public:
        Span();
        ~Span();

        Span(const Span &other);

        Span &operator=(const Span &other);

        Span(unsigned int &N);

        void addNumber();

        const int &shortestSpan();

        const int &longestSpan();

    };
