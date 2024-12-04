#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat constructor called" << std::endl;
    _brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other.type) {
    std::cout << "Cat copy constructor called" << std::endl;
    _brain = new Brain();
    *this = other;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete _brain;
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << "Cat assignment operator called" << std::endl;
    Animal::operator=(other);
    *_brain = *other._brain;
    return *this;
}

void    Cat::makeSound() const{
    std::cout << "Meow!" << std::endl;
}

Brain   *Cat::getBrain() const{
    return _brain;
}
