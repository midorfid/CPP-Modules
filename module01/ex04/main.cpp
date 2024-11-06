#include "./sed.hpp"

int main(int argc, char *argv[]) {
    if (argc != 4)
        return 1;
    Sed stream_ed;
    if (stream_ed.openfiles(argv[1])) {
        stream_ed.myReplace(argv[2], argv[3]);
        return 0;
    }
    return 1;
}
