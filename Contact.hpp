#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "lib.hpp"

class Contact {

public:
    void    getName() const;
    void    setName(str);

    Contact();
    ~Contact();
private:
    str     Name;
    // str     LastName;
    // str     NickName;
    // str     PhoneNum;
    // str     DarkestSecret;
};

#endif
//fisrt name last name nickname phone number darkest secret