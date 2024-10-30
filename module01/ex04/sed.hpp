#pragma once
#ifndef SED_H
#define SED_H

#include <fstream>
#include <string>

typedef std::string str;

class Sed {

    public:

        Sed(str filename, const str _old, const str _new);
        ~Sed();

        

    private:

        str         filename;
        str         filename_replace;
        const str   _old;
        const str   _new;

};

#endif