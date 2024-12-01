#pragma once
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(const std::string name);
        ~ScavTrap();

        ScavTrap(const ScavTrap &);

        ScavTrap &operator=(const ScavTrap &);

        void    attack(const std::string &target);

        void    guardGate();

};





#endif