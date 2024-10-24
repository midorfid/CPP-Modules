#include "./lib.hpp"

PhoneBook::PhoneBook() :  max_contacts(8), index(0), contacts_size(0) {
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::add() {
    str temp;

    if (this->contacts_size > this->max_contacts)
        this->index = 0;

    std::cout << "Enter Name:" << std::endl;
    std::cin >> temp;
    this->contacts[this->index].setName(temp);

    std::cout << "Enter Last Name:" << std::endl;
    std:: cin >> temp;
    this->contacts[this->index].setLastName(temp);

    std::cout << "Enter Nickname:" << std::endl;
    std:: cin >> temp;
    this->contacts[this->index].setNickName(temp);

    std::cout << "Enter Phone Number:" << std::endl;
    std:: cin >> temp;
    this->contacts[this->index].setPhoneNum(temp);

    std::cout << "Enter Darkest Secret:" << std::endl;
    std:: cin >> temp;
    this->contacts[this->index].setDarkestSecret(temp);
}

void PhoneBook::search() {
    str     res;
    //display
    std::cout << std::setw(10) << "1" << "|";
    std::cout << std::setw(10) << this->contacts[0].getName() << "|";
    std::cout << std::setw(10) << this->contacts[0].getLastName() << "|";
    std::cout << std::setw(10) << this->contacts[0].getNickName() << "|";
    std::cout << "Enter an index:" << std::endl;
    std::cin >> res;
    this->contacts[res[0] - 49].getName();
}