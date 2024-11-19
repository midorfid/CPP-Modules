#include "Harl.hpp"

int Harl::switchString(const std::string types[], std::string level) {
    for(int i = 0;i < 4; ++i) {
        if (types[i] == level)
            return (i);
    }
    return (-1);
}

void Harl::complain(std::string level) {
    void (Harl::*f[])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    const std::string types[4] = {"debug", "info", "warning", "error"};

    switch (this->switchString(types, level)) {
        case 0:
            (this->*f[0])();
            /* fall through*/
        case 1:
            (this->*f[1])();
            /* fall through*/
        case 2:
            (this->*f[2])();
            /* fall through*/
        case 3:
            (this->*f[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
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
