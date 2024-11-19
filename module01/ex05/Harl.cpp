#include "Harl.hpp"
#include <sstream>

void Harl::complain(std::string level) {
    void (Harl::*f[])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    std::istringstream iss(level);
    int num;
    iss >> num;
    (this->*f[num])();
}

void Harl::debug(void) {
    std::cout << "debug" << std::endl;
}

void Harl::error(void) {
    std::cout << "error" << std::endl;
}
void Harl::warning(void) {
    std::cout << "warning" << std::endl;
}
void Harl::info(void) {
    std::cout << "info" << std::endl;
}
