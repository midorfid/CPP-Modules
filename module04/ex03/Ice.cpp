#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Ice::Ice() : type("ice") { std::cout << "Ice constructor called" << std::endl; }

Ice::~Ice() { std::cout << "Ice destructor called" << std::endl; }

Ice::Ice(const Ice &other) {
    std::cout << "Ice copy constructor called" << std::endl;
    *this = other;
}

Ice &Ice::operator=(const Ice &other) {
    std::cout << "Ice assignment operator called" << std::endl;
    AMateria::operator=(other);
    return *this;
}

AMateria *Ice::clone() const{
    Ice *cloned = new Ice(*this);
    return cloned;
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at a " << target.getName() << " *" << std::endl;
}
