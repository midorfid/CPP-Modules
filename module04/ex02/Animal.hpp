#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
    protected:
        std::string type;
        Animal(const std::string);

    public:
        virtual ~Animal();
        
        Animal(const Animal &);

        Animal &operator=(const Animal &);

        virtual void    makeSound() const = 0;
        std::string     getType() const;
};


#endif
