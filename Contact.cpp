#include "./lib.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setName(str name) {
    this->Name = name;
}

void Contact::getName() const {
    std::cout << this->Name << std::endl;
}
