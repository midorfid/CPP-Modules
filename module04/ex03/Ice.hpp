#pragma once

#include "AMateria.hpp"

class Ice : public AMateria {
    private:
        std::string type;

    public:
        Ice();
        ~Ice();

        Ice(const Ice &);

        Ice &operator=(const Ice &);

        AMateria    *clone() const;
        void        use(ICharacter &target);
};
