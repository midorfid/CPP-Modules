#include "RPN.hpp"
#include <stdlib.h>
#include <cctype>
#include <string>
#include <stdexcept>
#include <iostream>

RPN::RPN() : _helper_c() {
	// std::cout << "constructor\n";
}

RPN::~RPN() {
	// std::cout << "destructor\n";
}

RPN::RPN(const RPN &other) : _helper_c(other._helper_c) {
	*this = other;
	// std::cout << "copy constructor\n";
}

RPN &RPN::operator=(const RPN &other) {
	if (&other != this)
		_helper_c = other._helper_c;
	return *this;
}


bool RPN::istoken(char &c) {
    std::string tokens = "+-/*";
    return tokens.find(c) != std::string::npos;
}

int RPN::calculateTwoInts(const int &first, const int &last, const char &op) {
	switch (op) {
		case '+':
			return first + last;
		case '-':
			return first - last;
		case '/':
			if (last == 0)
				throw std::logic_error("division by zero");
			return first / last;
		case '*':
			return first * last;
		default:
			throw std::logic_error("unknown error");
	}
}

void RPN::calculateRPN(char *input) {
	int	last, beforelast;
	for (int i = 0; input[i] != '\0'; ++i) {
        if (std::isdigit(static_cast<unsigned char>(input[i]))) {
			this->_helper_c.push(input[i] - '0');
		}
        else if (RPN::istoken(input[i])) {
			if (this->_helper_c.size() < 2) {
				throw std::logic_error("not enough args to perform an operation");
			}
			last = this->_helper_c.top();
			this->_helper_c.pop();
			beforelast = this->_helper_c.top();
			this->_helper_c.pop();
			this->_helper_c.push(RPN::calculateTwoInts(beforelast, last, input[i]));
		}
		else if (input[i] == ' '){
			continue;
		}
		else {
			throw std::logic_error("Error");
		}
    }
	std::cout << _helper_c.top() << std::endl;
}
