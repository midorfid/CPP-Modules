#include "PmergeMe.hpp"
#include <stdlib.h>
#include <errno.h>
#include <stdexcept>

void    PmergeMe::parseInput(int numbers_count, char **numbers) {
    vec.reserve(numbers_count);

    for (int i = 0; i < numbers_count; ++i) {
        char *end = NULL;
        unsigned long num = std::strtoul(numbers[i], end, 10);

        if (errno != 0 || *end != '\0')
            throw std::logic_error("couldn't parse the input.");
        vec.push_back(static_cast<unsigned int>(num));
    }
}
