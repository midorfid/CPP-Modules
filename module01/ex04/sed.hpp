#pragma once
#ifndef SED_H
#define SED_H

#include <fstream>
#include <string>
#include <iostream>

typedef std::string str;

class Sed {

    public:

        Sed( void );
        ~Sed();

        bool    openfiles(const str &filename);
        void    myReplace(str const &_old, str const &_new);

    private:

        // str                 &filename;
        str                 filename_replace;
        str                 _old;
        str                 _new;
        std::ofstream       outfile;
        std::ifstream       infile;
};

#endif