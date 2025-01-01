#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") { std::cout << "Cure constructor called" << std::endl; }

Cure::~Cure() { std::cout << "Cure destructor called" << std::endl; }

Cure::Cure(const Cure &other) : AMateria(other) {
    std::cout << "Cure copy constructor called" << std::endl;
    *this = other;
}

Cure &Cure::operator=(const Cure &other) {
    std::cout << "Cure assignment operator called" << std::endl;
    AMateria::operator=(other);
    return *this;
}

AMateria *Cure::clone() const{
    Cure *cloned = new Cure(*this);
    return cloned;
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
