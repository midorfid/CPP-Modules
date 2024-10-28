#include <string>
#include <iostream>

int main ( void ) {
    std::string str = "HI THIS IS BRAIN";

    std::string *stringPTR = new std::string(str);
    std::string &stringREF = str;

    std::cout << "str address: " << &str << std::endl;
    std::cout << "stringptr address: " << stringPTR << std::endl;
    std::cout << "stringref address: " << &stringREF << std::endl;

    std::cout << "str value: " << str << std::endl;
    std::cout << "stringptr value: " << *stringPTR << std::endl;
    std::cout << "stringref value: " << stringREF << std::endl;

    delete stringPTR;
    return 0;
}