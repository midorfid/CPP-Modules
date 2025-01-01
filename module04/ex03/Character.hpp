#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter {
    private:
        static const int    _maxMaterias = 4;
        AMateria            *_materias[_maxMaterias];
        std::string         _name;

    public:
        Character();
        Character(const std::string &name);
        ~Character();

        Character(const Character &);

        Character &operator=(const Character &);

        std::string const   &getName() const;
        void                equip(AMateria *m);
        void                unequip(int idx);
        void                use(int idx, ICharacter &target);
};
