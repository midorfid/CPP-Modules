#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie {


    public:

        Zombie( std::string name );
        ~Zombie( void );

        Zombie *newZombie( std::string name);
        void    randomChump( std::string name );


    private:

        std::string name;
        void    announce( void );

};

#endif