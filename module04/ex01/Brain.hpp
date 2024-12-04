#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
    public:
        std::string     ideas[100];

        Brain();
        ~Brain();

        Brain(const Brain &);
        Brain &operator=(const Brain &);
};

#endif
