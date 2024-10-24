#include "Phonebook.hpp"
#include <string.h>

int main() {
    PhoneBook PhoneBook;
    str input;

    while (1)
    {
        std::cin >> input;
        if(input.compare("EXIT") == 0)
            exit(EXIT_SUCCESS);
        if(input.compare("ADD") == 0)
            PhoneBook.add();
        // else if(input.compare("SEARCH") == 0)
        //     PhoneBook.search();
    }
    return(0)   
}
