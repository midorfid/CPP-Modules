#include "Harl.hpp"

const std::string debug = "0";
const std::string info = "1";
const std::string warning = "2";
const std::string error = "3";

int main(int argc, char *argv[]) {
    if (argc != 2)
        return (-1);
    Harl    test;

    test.complain(argv[1]);

    return (0);
}