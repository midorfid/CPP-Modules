#include "DiamondTrap.hpp"

int main(void) {
    DiamondTrap a("Ben");
    DiamondTrap b("test");

    std::cout << std::endl;

    b = a;

    std::cout << std::endl;

    b.attack("enemy");
    b.guardGate();
    b.highFivesGuys();
    b.whoAmI();

    std::cout << std::endl;

    return(0);
}
