#include "Zombie.hpp"

Zombie *Zombie::zombieHorde( int N, std::string name) {
    Zombie *zombieh = new Zombie[N];
    for (int i = 0;i < N; ++i) {
        zombieh[i].name = name;
    }
    return zombieh;
}
