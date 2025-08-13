#include "iter.hpp"
#include <string>

int main(void) {
    int intArr[] = {1,2,3,4,5,6};
    char charArr[] = {'q','w','e','r','t','y'};
    std::string strArr[] = {"asd","fgh","tery"};
    iter(intArr, 6, printElement);
    iter(charArr, 6, printElement);
    iter(strArr, 3, printElement);
}