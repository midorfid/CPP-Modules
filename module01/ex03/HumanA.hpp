#pragma once
#ifndef HUMANA_H
#define HUMANA_H

#include "./Weapon.hpp"

class HumanA {

    public:

        HumanA( std::string name, Weapon &gun );
        ~HumanA();

        void attack() const;

    private:

        std::string name;
        Weapon      &gun;
};


#endif