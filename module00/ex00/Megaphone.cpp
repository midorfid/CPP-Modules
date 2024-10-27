#include <iostream>
#include <string.h>
#include <cctype>

int    main(int argc, char *argv[]) {
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else {
        // std::string s[argc-1];
        for(int i = 1;i<argc;++i) {
            for(size_t j = 0;argv[i][j]!='\0';++j)
                argv[i][j] = std::toupper(static_cast<unsigned char>(argv[i][j]));
            std::cout << argv[i];
        }    
        std::cout << std::endl;
    }
    return(0); 
}