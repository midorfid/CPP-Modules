#include "Character.hpp"
#define nullptr NULL

Character::Character() {
    for(int i = 0;i<_maxMaterias;++i) {
        _materias[i] = nullptr;
    }
}

Character::Character(const std::string &name) : _name(name) {
    for(int i = 0;i<_maxMaterias;++i) {
        _materias[i] = nullptr;
    }
}

Character::~Character() {
    for(int i = 0;i<_maxMaterias;++i) {
        if (_materias[i] != nullptr)
            delete _materias[i];
    }
}

Character::Character(const Character &other) {
    *this = other;
}

Character   &Character::operator=(const Character &other) {
    if(this == &other)
        return *this;
    for (int i = 0;i < _maxMaterias; ++i) {
        if (_materias[i] != nullptr) {
            delete _materias[i];
            _materias[i] = other._materias[i]->clone();
        }
    }
    return *this;
}

std::string const   &Character::getName() const {
    return (_name);
}

void    Character::equip(AMateria *materia) {
    for(int i = 0;i<_maxMaterias;++i) {
        if (_materias[i] == nullptr) {
            _materias[i] = materia;
            break;
        }
    }
}

void    Character::unequip(int idx) {
    if (idx < 0 || idx >= _maxMaterias)
        return;
    delete _materias[idx];
    _materias[idx] = nullptr;
}

void    Character::use(int idx, ICharacter &target) {
    if (idx < 0 || idx >= _maxMaterias)
        return;
    if (_materias[idx] == nullptr)
        return;
    _materias[idx]->use(target);
}