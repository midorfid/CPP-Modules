#pragma once
#ifndef HUMANB_H
#define HUMANB_H

#include "./Weapon.hpp"

class HumanB {

    public:

        HumanB( std::string name );
        ~HumanB();

        void attack() const;
        void setWeapon( Weapon &gun );
    private:

        std::string name;
        Weapon      *gun;
};


#endif