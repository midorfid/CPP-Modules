#include "base.hpp"
#include <cstdlib>
#include <time.h>
#include <exception>
#include <iostream>

Base::~Base() {}

Base    *generate(void) {
    switch (rand() % 3)
    {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
    }
    return NULL;
}

void    identify(Base *p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
        return ;
    }
    else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
        return;   
    }
    else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
        return;   
    }
    std::cout << "wrong type" << std::endl;
    return;
}

void    identify(Base &p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }catch(std::exception &e) {
        try {
            dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }catch(std::exception &e) {
            try {
                dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            }catch(std::exception &e) {
                std::cout << "wrong type" << std::endl;
            }
        }
    }
}