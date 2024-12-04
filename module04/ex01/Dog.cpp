#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog constructor called" << std::endl;
    _brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other.type) {
    std::cout << "Dog copy constructor called" << std::endl;
    _brain = new Brain();
    *this = other;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete _brain;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog assignment operator called" << std::endl;
    Animal::operator=(other);
    *_brain = *other._brain;
    return *this;
}

void    Dog::makeSound() const{
    std::cout << "Woof!" << std::endl;
}

Brain *Dog::getBrain() const{
    return _brain;
}
