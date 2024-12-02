#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    type = other.type;
    return *this;
}

void    Animal::makeSound() const{
    std::cout << "*Animal noises*" << std::endl;
}

std::string     Animal::getType() const{
    return type;
}

Animal::Animal(const std::string type) : type(type) {
    std::cout << "Animal type constructor called" << std::endl;
}
