#pragma once
#ifndef WANIMAL_HPP
#define WANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
    protected:
        std::string type;
        WrongAnimal(const std::string);

    public:
        WrongAnimal();
        virtual ~WrongAnimal();
        
        WrongAnimal(const WrongAnimal &);

        WrongAnimal &operator=(const WrongAnimal &);

        void            makeSound() const;
        std::string     getType() const;
};


#endif