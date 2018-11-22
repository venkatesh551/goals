#include <iostream>
#include <exception>

class Test {

public:
    Test() {
        std::cout << "init" << std::endl;
//        throw std::runtime_error("hh");
    }

};

Test x{};


int main() {

    std::cout << "In main" << std::endl;
    return 0;
}
