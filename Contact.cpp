#include "./lib.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setName(str name) {
    this->Name = name;
}

str Contact::getName() const {
    return this->Name;
}
