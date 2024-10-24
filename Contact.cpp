#include "./lib.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setName(str name) {
    this->Name = name;
}

str Contact::getName() const {
    return this->Name;
}

void Contact::setLastName(str lastname) {
    this->LastName = lastname;
}

str Contact::getLastName() const{
    return this->LastName;
}

void Contact::setNickName(str nickname) {
    this->NickName = nickname;
}

str Contact::getNickName() const {
    return this->NickName;
}

void Contact::setPhoneNum(str phonenum) {
    this->PhoneNum = phonenum;
}

str Contact::getPhoneNum() const {
    return this->PhoneNum;
}

void Contact::setDarkestSecret(str darkestsecret) {
    this->DarkestSecret = darkestsecret;
}

str Contact::getDarkestSecret() const {
    return this->DarkestSecret      ;
}
