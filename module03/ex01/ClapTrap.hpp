#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {

    protected:
        ClapTrap(const std::string, unsigned int, unsigned int, unsigned int);

        std::string                     Name;
        unsigned int                    hp;
        unsigned int                    energy;
        unsigned int                    attack_dmg;

    public:
        ClapTrap(const std::string);
        ClapTrap();
        ~ClapTrap();
        ClapTrap(const ClapTrap&);
        ClapTrap &operator=(const ClapTrap &);

        void    attack(const std::string &target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);

};

#endif
