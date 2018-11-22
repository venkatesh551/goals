#include <iostream>

class A {

public:
    void print()  && {
        std::cout << x << std::endl;
    }

private:
    int x{};
};

A f() {
    A temp;
    return temp;
}

int main() {

    f().print();

    return 0;
}
