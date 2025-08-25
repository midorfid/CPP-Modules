#pragma once

#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
    public:
        MutantStack() {}
        ~MutantStack() {}

        MutantStack(const MutantStack &other) { *this = other;}
        MutantStack &operator=(const MutantStack &other) {
            std::stack<T, Container>::operator=(other);
            return *this;
        }

        typedef typename Container::iterator iterator;

        iterator    begin() { return this->c.begin(); }
        
        iterator    end() { return this->c.end(); }
};
