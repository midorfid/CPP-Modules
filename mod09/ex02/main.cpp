#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <string>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cout << "minimum 2 numbers required to sort";
    }
	
    PmergeMe    vecSort(argc - 1, ++argv);
}
