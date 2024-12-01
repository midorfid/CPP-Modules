#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name", 100, 50, 30), Name("") {
    std::cout << "DT constructor called" << std::endl;
} 

DiamondTrap::DiamondTrap(std::string Name) : ClapTrap(Name + "_clap_name", 100, 50, 30), Name(Name) {
    std::cout << "DT constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DT destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other), Name(other.Name) {
    std::cout << "DT copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    std::cout << "DT assignment operator called" << std::endl;
    FragTrap::operator=(other);
    ScavTrap::operator=(other);
    Name = other.Name;
    return(*this);
}

void DiamondTrap::whoAmI() const{
    std::cout << "My name is " << Name << " ClapTrap name is " << ClapTrap::Name << std::endl;
}
