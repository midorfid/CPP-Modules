#pragma once
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
    public:
        void whoAmI() const;

        DiamondTrap();
        ~DiamondTrap();
        DiamondTrap(std::string);

        DiamondTrap(const DiamondTrap &);

        DiamondTrap &operator=(const DiamondTrap &);
    private:
        std::string Name;
};


#endif
