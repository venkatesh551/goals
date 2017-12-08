#include <iostream>


class Test {

public:

    Test &  operator = (const Test &src) {
        a = src.a;
        return *this;
    }

    int a;

};

int main() 
{

    Test a;

    Test b{a};
    std::cout << a.a << " " << b.a << std::endl;

    return 0;
}
