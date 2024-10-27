#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "lib.hpp"

class Contact {

public:
    str    getName() const;
    void    setName(str);

    str    getLastName() const;
    void    setLastName(str);

    str    getNickName() const;
    void    setNickName(str);

    str    getPhoneNum() const;
    void    setPhoneNum(str);

    str    getDarkestSecret() const;
    void    setDarkestSecret(str);

    Contact();
    ~Contact();
private:
    str     Name;
    str     LastName;
    str     NickName;
    str     PhoneNum;
    str     DarkestSecret;
};

#endif
//fisrt name last name nickname phone number darkest secret