#include "./lib.hpp"

PhoneBook::PhoneBook() :  max_contacts(8), index(0), contacts_size(0) {
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::add() {
    str name;

    if (this->contacts_size > this->max_contacts)
        this->index = 0;
    std::cout << "Enter Name:" << std::endl;
    std::cin >> name;
    this->contacts[this->index].setName(name); 
}

void PhoneBook::search() {
    str     res;
    //display
    std::cout << "Enter an index:" << std::endl;
    std::cin >> res;
    this->contacts[res[0] - 49].getName();
}