#include "./Zombie.hpp"

int main( void ) {
    Zombie *z = NULL;

    z = z->newZombie("Undying");
    z->randomChump("ghoul");
    delete z;
}
