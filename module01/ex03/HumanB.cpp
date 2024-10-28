#include "./HumanB.hpp"

HumanB::HumanB( std::string name ) : name(name) {
}

HumanB::~HumanB ( void ) {

}

void HumanB::attack() const{
    std::cout << this->name << " attacks with their " << this->gun->getType() << std::endl;
}

void HumanB::setWeapon( Weapon &gun ) {
    this->gun = &gun;
}