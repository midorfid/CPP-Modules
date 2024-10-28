#pragma once
#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

class Weapon {

    public:

        Weapon( std::string name );
        Weapon( void );
        ~Weapon();

        const std::string   &getType( void ) const;
        void                setType( std::string name );

    private:

        std::string type;

};







#endif