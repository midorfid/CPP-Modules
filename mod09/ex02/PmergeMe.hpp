#pragma once

#include <vector>
#include <string>

class PmergeMe {
    private:
        std::vector<unsigned int> vec;
        PmergeMe();

    public:
        PmergeMe(std::string &s);

        ~PmergeMe();
        
        PmergeMe(const PmergeMe &other);
        
        PmergeMe &operator=(const PmergeMe &other);
        
        void	printSorted();

        void	sortVec();

        void    parseInput(int numbers_count, char **numbers);
};
