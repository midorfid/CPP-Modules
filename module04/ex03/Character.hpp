#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter {
    private:
        AMateria        *inventory[4];
        std::string     name;

    public:
        Character();
        ~Character();

        Character(const Character &);

        Character &operator=(const Character &);
        
};
