#include "PmergeMe.hpp"
#include <stdlib.h>
#include <errno.h>
#include <stdexcept>
#include <iostream>
#include <utility>
#include <algorithm>

int PmergeMe::_compCount = 0;

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
	(void)other;
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
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::sortVec(std::vector<int> &container, int pair_lvl) {
	typedef std::vector<int>::iterator Iterator;
	
	int pair_units = container.size() / pair_lvl;

	bool is_odd = pair_units % 2 == 1;
	
	Iterator begin = container.begin();
	Iterator last = _next(container.begin(), pair_lvl * pair_units);
	Iterator end = _next(last, -(is_odd * pair_lvl));

	int jump = 2 * pair_lvl;
	for (Iterator it = begin; it != end; std::advance(it, jump)) {
		
		Iterator this_pair = _next(it, pair_lvl - 1);
		Iterator next_pair = _next(it, pair_lvl * 2 - 1);
	
		// std::cout << "this pair:" << *this_pair << '\n';
		// std::cout << "next pair:" << *next_pair << '\n';

		if (!_comp(this_pair, next_pair)) {
			_swap_pair(this_pair, pair_lvl);		
		}
	}
	sortVec(container, pair_lvl * 2);

	std::vector<Iterator> main;
	std::vector<Iterator> pend;

	main.insert(begin, pair_lvl - 1);
	main.insert(begin, pair_lvl * 2 - 1);

	
}

