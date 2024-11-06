#include "./sed.hpp"

Sed::Sed( void ) {
}

Sed::~Sed () {
    if (outfile.is_open())
        outfile.close();
    if (infile.is_open())
        infile.close();
}

bool Sed::openfiles(const str &filename) {
    this->filename_replace = filename;
    this->filename_replace += ".replace";
    outfile.open(filename_replace.c_str(), std::ios::out);
    infile.open(filename.c_str(), std::ios::in);
    if (!outfile.is_open())
        return false;
    if (!infile.is_open()) {
        outfile.close();
        return false;
    }    
    return true;
}

void Sed::myReplace(str const &_old, str const &_new) {
    this->_old = _old;
    this->_new = _new;
    str line;
    for (;std::getline(infile, line);) {
        if (infile.eof())
            break;
        for(size_t i = 0,pos = 0;i+this->_old.size()<=line.size();++i) {
            pos = line.find(this->_old, i);
            if (pos != str::npos) {
                line.erase(pos, this->_old.size());
                line.insert(pos, this->_new);
            }
        }
        outfile << line << std::endl;
        if (outfile.fail()) {
            std::cerr << "failed to write" << std::endl;
            break;
        }
    }
}