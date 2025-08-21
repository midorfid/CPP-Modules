#pragma once

#include <vector>
#include <string>

#define SORTED 1
#define UNSORTED 0

class PmergeMe {
    private:
        static int _compCount = 0;
        PmergeMe();

        template <typename T> static  bool    _comp(const T &a, const T &b) const {
            ++_compCount;
            return a < b;
        }

        template <typename T> static  void    _swap_pair(T &it, int pair_lvl) const {
            T   start = it;
            T   end = std::next(start, pair_lvl);
            std::iter_swap(start, end);
        }

    public:
        PmergeMe();

        ~PmergeMe();
        
        PmergeMe(const PmergeMe &other);
        
        PmergeMe &operator=(const PmergeMe &other);
        
        void	printVec(const std::vector<int> &vec, bool isSorted);

        void	sortVec(std::vector<int> &vec, int pair_lvl);

        std::vector<int>    parseInput(int numbers_count, char **numbers);

};
