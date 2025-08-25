#pragma once

#include <stdint.h>

class Data {
    public:
        int i;
        char c;

};

class Serializer {
    public:
        ~Serializer();
        Serializer(const Serializer &other);

        Serializer &operator=(const Serializer &other);

        static uintptr_t   serialize(Data *ptr);

        static Data        *deserialize(uintptr_t raw);
    private:
        Serializer();
};
