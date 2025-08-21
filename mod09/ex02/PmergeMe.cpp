#include "PmergeMe.hpp"
#include <stdlib.h>
#include <errno.h>
#include <stdexcept>
#include <iostream>
#include <utility>
#include <algorithm>

PmergeMe::PmergeMe() {
	std::cout << "constructor";
}

PmergeMe::~PmergeMe() {
	std::cout << "destructor";
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	std::cout << "copy constructor";
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {

	return *this;
}


std::vector<int>    PmergeMe::parseInput(int numbers_count, char **numbers) {
    std::vector<int> unsortedVec;
	
	unsortedVec.reserve(numbers_count);
	std::cout << "capacity: " << unsortedVec.capacity() << std::endl;

    for (int i = 0; i < numbers_count; ++i) {
		char *end = NULL;
        long num = std::strtol(numbers[i], &end, 10);

        if (errno != 0)
            throw std::logic_error("couldn't parse the input.");
        unsortedVec.push_back(static_cast<int>(num));
	}
	printVec(unsortedVec, UNSORTED);
	return unsortedVec;
}

void	PmergeMe::printVec(const std::vector<int> &v, bool isSorted) {
	switch(isSorted) {
		case SORTED:
			std::cout << "After:	";
			break;
		default:
			std::cout << "Before:	";
			break;
	}
	for (std::vector<int>::const_iterator it = unsortedVec.begin(); it != unsortedVec.end(); ++it) {
		std::cout << unsortedVec.back() << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::sortVec(std::vector<int> &container, int pair_lvl) {
	std::vector<int>::iterator &begin = container.begin();
	std::vector<int>::iterator &end = container.end();
	bool	is_odd = false;

	if (container.size() % 2 == 1)
		is_odd = true;
	

	for (std::vector<int>::iterator &it = begin; it != end; std::advance(it, pair_lvl)) {
		std::vector<int>::iterator &next = std::next(it, pair_lvl);
	
		if (!_comp(it, next))
			
	}
	
	sortVec(container, pair_lvl * 2);
}

