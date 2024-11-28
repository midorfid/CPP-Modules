#include "ClapTrap.hpp"

int main(void) {

    ClapTrap player1("John");
    ClapTrap player2(player1);

    player1.attack("monster");
    player1.beRepaired(10);
    player1.takeDamage(21);
    ClapTrap player3;
    player3 = player1;

    return(0);
}
