#pragma once
#include <stack>

class RPN {
    private:
        std::stack<int>  _helper_c;

    public:
        RPN();
        ~RPN();

        RPN(const RPN &other);
        
        RPN &operator=(const RPN &other);

        void calculateRPN(char *input);

        static bool istoken(char &c);

        static int  calculateTwoInts(const int &first, const int &last, const char &op);
};
