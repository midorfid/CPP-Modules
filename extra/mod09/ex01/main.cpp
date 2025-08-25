#include "RPN.hpp"
#include <iostream>
#include <exception>

int main(int argc, char *argv[]) {
    RPN test;
    
    if (argc != 2) {
        std::cout << "provide an input in double quotes\n";
        return(1);
    }
    try {
        test.calculateRPN(argv[1]);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    return(0);
}