#include <iostream>
#include "Array.hpp"

int main(void) {
     std::cout << "-----------------------------------------------------" << std::endl;

    Array< float > test;

    Array< int > intArray( 10 );
    Array< int > intArray2( 10 - 5 );

    for ( unsigned int i = 0; i < intArray.size(); i++ ) {
        intArray[i] = i * 2;
        std::cout << intArray[i] << ' ';
    }


    try {
        std::cout << "Accessing a valid index: " << intArray[5] << std::endl;
        std::cout << "Accessing an invalid index: " << intArray[10] << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "-----------------------------------------------------" << std::endl;
}