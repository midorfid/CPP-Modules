#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <string>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cout << "minimum 2 numbers required to sort";
    }
	
    PmergeMe    vecSort;


    
    std::vector<int> v = vecSort.parseInput(argc - 1, ++argv);
    vecSort.sortVec(v, 1);
}
