#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    public:
        MateriaSource();
        ~MateriaSource();

        MateriaSource(const MateriaSource &);

        MateriaSource &operator=(const MateriaSource &);

        void learnMateria(AMateria *materia);
        AMateria *createMateria(std::string const &type);
    
    
    private:
        static const int    _maxMaterias = 4;
        AMateria            *_learnedMaterias[_maxMaterias];
};
