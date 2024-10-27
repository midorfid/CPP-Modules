#include "./lib.hpp"

PhoneBook::PhoneBook() :  max_contacts(8), index(0), contacts_size(0) {
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::add() {
    str temp;
    int i = 0;

    if (this->contacts_size - i >= this->max_contacts)
        this->index = 0;
    system("clear");
    std::cout << "Enter Name:" << std::endl;
    std::cin >> temp;
    this->contacts[this->index].setName(temp);
    system("clear");
    std::cout << "Enter Last Name:" << std::endl;
    std:: cin >> temp;
    this->contacts[this->index].setLastName(temp);
    system("clear");
    std::cout << "Enter Nickname:" << std::endl;
    std:: cin >> temp;
    this->contacts[this->index].setNickName(temp);
    system("clear");
    std::cout << "Enter Phone Number:" << std::endl;
    std:: cin >> temp;
    this->contacts[this->index].setPhoneNum(temp);
    system("clear");
    std::cout << "Enter Darkest Secret:" << std::endl;
    std:: cin >> temp;
    this->contacts[this->index].setDarkestSecret(temp);
    system("clear");
    this->index++;
    if (this->contacts_size - i < this->max_contacts)
        this->contacts_size++;
    else
        i +=8;
}

void PhoneBook::search() {
    str     res;
    char    c;
    //display
    system("clear");
    for (int i = 0; i<this->contacts_size; ++i) {
        //truncate
        //index
        c = static_cast<char>(i + 49);
        std::cout << std::setw(10) << c << "|";
        //name
        res = this->contacts[i].getName();
        if (res.size() > 10)
            res.replace(9,res.size(),".", 1);
        std::cout << std::setw(10) << res << "|";
        //lastname
        res = this->contacts[i].getLastName();
        if (res.size() > 10)
            res.replace(9,res.size(),".", 1);
        std::cout << std::setw(10) << res << "|";
        //nickname
        res = this->contacts[i].getNickName();
        if (res.size() > 10)
            res.replace(9,res.size(),".", 1);
        std::cout << std::setw(10) << res << "|" << std::endl;
    }
    int j = 0;
    for (;j < 1;) {
        j = 0;
        std::cout << "Enter an index:" << std::endl;
        std::cin >> res;
        //parse index
        for(size_t i = 0;i<res.size();++i) {
            if (res[i] < '0' || res[i] > '9') {
                std::cout << "Not numerical input! Try again!" << std::endl;
                break ;
            }
            j = j*10 + (res[i] - 48);
            if (j > 8) {
                std::cout << "Max capacity of the Phonebook is 8! Try again!" << std::endl;
                j = 0;
                break ;
            }
            else if (this->contacts_size < j || j < 1) {
                std::cout << "The contact with this index doesn't exist!" << std::endl;
                j = 0;
                break ;
            }
        }
    }
    //display info one field per line
    std::cout << this->contacts[j-1].getName() << std::endl;
    std::cout << this->contacts[j-1].getLastName() << std::endl;
    std::cout << this->contacts[j-1].getNickName() << std::endl;
    std::cout << this->contacts[j-1].getPhoneNum() << std::endl;
    std::cout << this->contacts[j-1].getDarkestSecret() << std::endl;
}
