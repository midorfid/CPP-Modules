#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "./lib.hpp"

typedef std::string str;
class PhoneBook {

public:
    void    add();
    void    search();

    PhoneBook();
    ~PhoneBook();    
private:
    const int   max_contacts;
    int         index;
    int         contacts_size;
    Contact     contacts[8];
};

#endif
//add
//fisrt name last name nickname phone number darkest secret
//cant have empty fields