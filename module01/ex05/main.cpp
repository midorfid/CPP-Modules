#include "Harl.hpp"

const std::string debug = "0";
const std::string info = "1";
const std::string warning = "2";
const std::string error = "3";

int main(void) {
    Harl    test;

    test.complain(error);
    test.complain(info);
    test.complain(error);
    test.complain(warning);
    test.complain(warning);
    test.complain(debug);

    return (0);
}