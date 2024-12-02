#pragma once
#ifndef WCAT_HPP
#define WCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    public:
        WrongCat();
        ~WrongCat();

        WrongCat(const WrongCat &);
        WrongCat &operator=(const WrongCat &);

        void    makeSound() const;
};

#endif
