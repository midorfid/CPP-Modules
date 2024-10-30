#include "./sed.hpp"

Sed::Sed( str filename, const str _old, const str _new ) : filename(filename), filename_replace(filename), _old(_old), _new(_new) {
    filename_replace.append(".replace", 0, sizeof(".replace"));
    std::ofstream outfile(filename_replace, std::ios::out);
    std::ifstream infile(filename, std::ios::in);
    // if (outfile.is_open() && infile.is_open())
    str line;
    for (;std::getline(infile, line);) {
        for(size_t i,pos = 0;i+this->_old.size()<=line.size();++i) {
            pos = (line + i).find(this->_old);
            if (pos != str::npos) {
                line.erase(pos, this->_old.size());
                line.insert(pos, this->_new);
            }
        }
        outfile << line;
    }
    outfile.close();
    infile.close();
}