#include "./lib.hpp"

int main() {
    PhoneBook Phonebook;
    str input;

    while (1)
    {
        std::cout << "EXIT, ADD, SEARCH:" << std::endl;
        std::cin >> input;
        if(input.compare("EXIT") == 0)
            break ;
        if(input.compare("ADD") == 0)
            Phonebook.add();
        else if(input.compare("SEARCH") == 0)
            Phonebook.search();
    }
    return(0);
}
