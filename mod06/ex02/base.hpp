#pragma once


class Base {
    public:
        virtual ~Base() = 0;
};

Base    *generate(void);

void    identify(Base *p);

void    identify(Base &p);

class A: public Base {};

class B: public Base {};

class C: public Base {};
