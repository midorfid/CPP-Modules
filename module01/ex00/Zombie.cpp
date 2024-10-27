#include "./Zombie.hpp"

Zombie::Zombie(std::string name) {
    this->name = name;
    std::cout << "zombie " << name << " has arrised" << std::endl;
}

Zombie::~Zombie() {
    std::cout << "zombie " << this->name << " has died" << std::endl;
}

void Zombie::announce() {
    std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}



