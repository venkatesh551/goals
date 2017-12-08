//#include <iostream>
#include <memory>


class Interface {

    public:
        virtual void print() = 0;
         ~Interface() {};
};


class Derived : public Interface {

    public:
        void print() override {
//            std::cout << "Derived print API" << std::endl;
        }
        ~Derived() {
//            std::cout << "Derived dtor called" << std::endl;
        }
};


int main() {

    std::shared_ptr<Interface> ptr{new Derived};


    return 0;
}
