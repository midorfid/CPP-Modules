#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie {


    public:

        Zombie( void );
        ~Zombie( void );

        Zombie *zombieHorde( int N, std::string name );

    private:

        std::string name;
        void    announce( void );

};

#endif