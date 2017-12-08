#include <iostream>

class Base {
    public:
        virtual void print() {
            std::cout << "Base" << std::endl;
        }
        virtual ~Base() {
        }
};

class Derived {
    public:
        void print() {
            std::cout << "Derived" << std::endl;
        }
};


int main() {
    Base *base = new Base;
    Derived *d = dynamic_cast<Derived *>(base);
    if (d == nullptr) {
        std::cout << "Invalid Conversion" << std::endl;
    }
    delete base;
    return 0;
}
