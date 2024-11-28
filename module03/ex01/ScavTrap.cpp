#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("", 100, 50, 20) {std::cout << "Default ST constructor called" << std::endl;}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name, 100, 50, 20) {std::cout << "Name ST constructor called" << std::endl;}

ScavTrap::~ScavTrap() {std::cout << "Default ST destructor called" << std::endl;}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy) {
    std::cout << "ST copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    std::cout << "ST assignment operator called" << std::endl;
    ClapTrap::operator=(other);
    return *this;
}

void ScavTrap::attack(const std::string &target) {
    if (this->hp == 0 || this->energy == 0) {
        std::cout << this->Name << " is out of hp/energy" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing ";
    std::cout << this->attack_dmg << " points of damage!" << std::endl;
    --energy;
}

void ScavTrap::guardGate(void) {
    std::cout << "ScavTrap " << Name << " is now in Gate keeper mode!" << std::endl;
}
