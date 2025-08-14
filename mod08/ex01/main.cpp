#include "Span.hpp"
#include <iostream>
#include <exception>
#include <vector>

int main(void) {
    unsigned int u = 100;
    
    Span<int> s(u);

    try {
        for (int i = 0; i < 10; ++i) {
            int rng_int = rand() % 100 + 1;
            s.addNumber(rng_int);
            std::cout << s[i] << ' ';
        }

        // s.addNumber(100);
        // s.addNumber(17);

        std::cout << s.longestSpan(); 
        
        std::vector<int> int_vec;

        int_vec.push_back(10);
        int_vec.push_back(10);
        int_vec.push_back(10);
        int_vec.push_back(10);
        int_vec.push_back(10);
        int_vec.push_back(10);
        int_vec.push_back(10);
        int_vec.push_back(10);
        int_vec.push_back(10);

        s.addNumber(int_vec.begin(), int_vec.end());

        Span<int> ss = s;

        for (int i = 0; i < 20; ++i)
            std::cout << s[i] << ' ';

    } catch(std::exception &e) {
        std::cout << "caught!" << std::endl;
    }
}
