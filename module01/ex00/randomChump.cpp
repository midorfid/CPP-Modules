#include "Zombie.hpp"

void Zombie::randomChump( std::string name ) {
    Zombie newZomb(name);
    newZomb.announce();
    return ;
}