#include "ScavTrap.hpp"

int main(void) {

    ScavTrap player1("John");
    ScavTrap player2(player1);
    ClapTrap    player4("lox");

    player4.attack("monster");
    player1.attack("monster");
    player1.beRepaired(10);
    player1.takeDamage(21);
    ScavTrap player3;
    player3 = player1;

    return(0);
}
