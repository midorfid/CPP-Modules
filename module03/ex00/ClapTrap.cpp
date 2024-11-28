#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name(""), hp(10), energy(10), attack_dmg(0) { std::cout << "Default constructor called" << std::endl;}

ClapTrap::ClapTrap(const std::string name) : Name(name), hp(10), energy(10), attack_dmg(0) { std::cout << "Constructor called" << std::endl;}

ClapTrap::~ClapTrap() { std::cout << "Destructor called" << std::endl;}

void ClapTrap::attack(const std::string &target) {
    if (this->hp == 0 || this->energy == 0) {
        std::cout << this->Name << " is out of hp/energy" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing ";
    std::cout << this->attack_dmg << " points of damage!" << std::endl;
    --energy;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hp == 0) {
        std::cout << this->Name << " is out of hp" << std::endl;
        return ;
    }
    this->hp = amount >= hp ? 0 : hp - amount;
    std::cout << "ClapTrap " << this->Name << " has taken " << amount << " damage, and now has ";
    std::cout << this->hp << " hp!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->hp == 0 || this->energy == 0) {
        std::cout << this->Name << " is out of hp/energy" << std::endl;
        return ;
    }
    this->hp += amount;
    std::cout << "ClapTrap " << this->Name << " has repaired " << amount << " hp, and now has ";
    std::cout << this->hp << " hp!" << std::endl;
    --energy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    std::cout << "Assignment operator called" << std::endl;
    Name = other.Name;
    hp = other.hp;
    energy = other.energy;
    attack_dmg = other.attack_dmg;
    return(*this);
}

ClapTrap::ClapTrap(const ClapTrap &other) : Name(other.Name), hp(other.hp), energy(other.energy), attack_dmg(other.attack_dmg) {
    std::cout << "Copy constructor called" << std::endl;
}
