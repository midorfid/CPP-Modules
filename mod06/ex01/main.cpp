#include "Serializer.hpp"
#include <iostream>
#include <iomanip>

int main(void) {
    Data d1;
    Data *d = &d1;
    uintptr_t uptr = Serializer::serialize(d);
    std::cout << "og " << d << std::endl;
    std::cout << "mine " << std::hex << uptr << std::endl;
    std::cout << "deserialized " << Serializer::deserialize(uptr) << std::endl;
}
