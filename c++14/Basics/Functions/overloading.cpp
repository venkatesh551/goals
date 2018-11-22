#include <iostream>


class Base {

public:
    void print(int a, int b) {
        std::cout << "a = " << a << " b = " << b << std::endl;
    }

};

class Derived : public Base {

public:
    void print(double x) {
        std::cout << "x = "  << x << std::endl;
    }

};

int main() {


    Derived d;
    d.print(2);
    d.print(2, 3);



    return 0;
}
