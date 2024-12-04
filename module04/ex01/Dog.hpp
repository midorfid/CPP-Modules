#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <cstring>

class Dog : public Animal {
    public:
        Dog();
        ~Dog();

        Dog(const Dog &);
        Dog &operator=(const Dog &);

        void    makeSound() const;
        Brain   *getBrain() const;

    private:
        Brain *_brain;
};

#endif
