#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("", 100, 100, 30) {std::cout << "Default FT constructor called" << std::endl;}

FragTrap::FragTrap(const std::string name) : ClapTrap(name, 100, 100, 30) {std::cout << "Name FT constructor called" << std::endl;}

FragTrap::~FragTrap() {std::cout << "Default FT destructor called" << std::endl;}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
    std::cout << "FT copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    std::cout << "FT assignment operator called" << std::endl;
    ClapTrap::operator=(other);
    return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << Name << " requests a friendly High Five!" << std::endl;
}
