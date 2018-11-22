#include <iostream>


int main() {

    double x;
    try {
        std::cout << "before" << std::endl;
        x = 1/0;

    }catch(...) {
        std::cout << "catched" << std::endl;
    }
    std::cerr << "crash\n" << x;

    return 0;
}
