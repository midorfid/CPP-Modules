#pragma once

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        const std::string type;

    public:
        AMateria(std::string const &type);

        virtual ~AMateria();

        std::string const &getType() const;

        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);

        AMateria &operator=(const AMateria &);
};
