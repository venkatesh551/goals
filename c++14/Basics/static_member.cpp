#include <string>
#include <iostream>

int add (int a, int b) {

    return a + b;

}

class Test {

    public:
        static std::string str;
        static constexpr float a{1.0};
        // static const float c5 = 1.0; // error
        // static const int c3 = add(1, 2); // error
};

// std::string  Test::str = "";


int main() {


    std::cout << Test::str << std::endl;

    return 0;
}
