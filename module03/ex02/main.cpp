#include "FragTrap.hpp"

int main(void) {

    FragTrap player1("John");
    FragTrap player2(player1);
    // ClapTrap    player4("lox");

    // player4.attack("monster");
    player1.attack("monster");
    player1.beRepaired(10);
    player1.takeDamage(21);
    FragTrap player3;
    player3 = player1;
    player3.highFivesGuys();

    return(0);
}
