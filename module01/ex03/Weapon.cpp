#include "./Weapon.hpp"

Weapon::Weapon( std::string name ) {
    this->type = name;
}

Weapon::Weapon( void ) {}

Weapon::~Weapon() {
    
}

const std::string &Weapon::getType( void ) const {
    return this->type;
}

void Weapon::setType( std::string name ) {
    this->type = name;
}