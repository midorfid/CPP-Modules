#pragma once

#include "AMateria.hpp"

class Cure : public AMateria {
    public:
        Cure();
        ~Cure();

        Cure(const Cure &);

        Cure &operator=(const Cure &);

        AMateria    *clone() const;
        void        use(ICharacter &target);
};
