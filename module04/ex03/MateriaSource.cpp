#include "MateriaSource.hpp"

#define nullptr NULL

MateriaSource::MateriaSource() {
    for (int i = 0;i <_maxMaterias;++i) {
        _learnedMaterias[i] = nullptr;
    }
}

MateriaSource::~MateriaSource() {
    for (int i = 0;i <_maxMaterias;++i) {
        if (_learnedMaterias[i] != nullptr)
            delete _learnedMaterias[i];
    }
}

MateriaSource::MateriaSource(const MateriaSource &other) {
    *this = other;
}

MateriaSource   &MateriaSource::operator=(const MateriaSource &other) {
    if(this == &other)
        return *this;
    for (int i = 0;i < _maxMaterias; ++i) {
        if (_learnedMaterias[i] != nullptr) {
            delete _learnedMaterias[i];
            _learnedMaterias[i] = other._learnedMaterias[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *other) {
    for (int i = 0;i < _maxMaterias; ++i) {
        if (_learnedMaterias[i] == nullptr) {
            _learnedMaterias[i] = other;
            break;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0;i <_maxMaterias;++i) {
        if (_learnedMaterias[i] != nullptr && _learnedMaterias[i]->getType() == type)
            return (_learnedMaterias[i]->clone());
    }
    return (nullptr);
}
