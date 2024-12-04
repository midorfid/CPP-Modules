#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
    Cat c;
    Animal &A = c;
    A.makeSound();

    return(0);
}
