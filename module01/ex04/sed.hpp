#pragma once
#ifndef SED_H
#define SED_H

#include <fstream>
#include <string>
#include <iostream>

// typedef std::string str;

class Sed {

    public:

        Sed( void );
        ~Sed();

        bool    openfiles(const std::string &filename);
        void    myReplace(std::string const &_old, std::string const &_new);

    private:

        // str                 &filename;
        std::string                 filename_replace;
        std::string                 _old;
        std::string                 _new;
        std::ofstream       outfile;
        std::ifstream       infile;
};

#endif