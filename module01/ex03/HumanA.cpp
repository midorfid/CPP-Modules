#include "./HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &gun ) : name(name), gun(gun) {
}

HumanA::~HumanA ( void ) {

}

void HumanA::attack() const {
    std::cout << this->name << " attacks with their " << this->gun.getType() << std::endl;
}