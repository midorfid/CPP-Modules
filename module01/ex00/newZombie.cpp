#include "Zombie.hpp"

Zombie *Zombie::newZombie( std::string name ) {
    Zombie *newZomb = new Zombie(name);
    return newZomb;
}