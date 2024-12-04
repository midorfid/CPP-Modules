#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <cstring>

class Cat : public Animal {
    public:
        Cat();
        ~Cat();

        Cat(const Cat &);
        Cat &operator=(const Cat &);

        void    makeSound() const;
        Brain   *getBrain() const;

    private:
        Brain   *_brain;
};

#endif
