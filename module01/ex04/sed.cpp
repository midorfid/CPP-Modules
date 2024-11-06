#include "./sed.hpp"

Sed::Sed( void ) {
}

Sed::~Sed () {
}

bool Sed::openfiles(const std::string &filename) {
    this->filename_replace = filename + ".replace";
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

void Sed::myReplace(std::string const &_old, std::string const &_new) {
    this->_old = _old;
    this->_new = _new;
    std::string line;
    for (;std::getline(infile, line);) {
        for(size_t pos = 0;(pos = line.find(this->_old, pos)) != std::string::npos;) {
            line.erase(pos, this->_old.size());
            line.insert(pos, this->_new);
            pos += this->_new.size();
        }
        outfile << line << std::endl;
        if (outfile.fail()) {
            std::cerr << "failed to write" << std::endl;
            break;
        }
    }
    if(infile.bad()) {
        std::cerr << "failed to read input file" << std::endl;
    }
    infile.close();
    outfile.close();
}
