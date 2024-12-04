#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
    {
        std::cout << "------------------COPY TEST------------------" << std::endl;

        Cat cat1;
        Cat cat2;

        std::cout << std::endl;

        cat1.getBrain()->ideas[0] = "Hello World!";
        cat1.getBrain()->ideas[1] = "cat1, ideas1 original msg";

        cat2 = cat1;

        cat2.getBrain()->ideas[1] = "cat2, ideas1 changed msg";

        std::cout << std::endl;

        std::cout << "cat1 brain[0,1]" << std::endl;
        std::cout << cat1.getBrain()->ideas[0] << std::endl;
        std::cout << cat1.getBrain()->ideas[1] << std::endl;

        std::cout << std::endl;

        std::cout << "cat2 brain[0,1]" << std::endl;
        std::cout << cat2.getBrain()->ideas[0] << std::endl;
        std::cout << cat2.getBrain()->ideas[1] << std::endl;

        std::cout << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "------------------CONSTRUCTORS AND DESTRUCTORS TEST------------------" << std::endl;
        std::cout << std::endl;

        Animal  *A[100];

        for(int i = 0; i < 50; ++i)
            A[i] = new Cat();
        for(int i = 50; i < 100; ++i)
            A[i] = new Dog();

        std::cout << std::endl;
        
        for(int i = 0;i <100; ++i)
            delete A[i];
    }
    return(0);
}
