#include <iostream>
#include <string>


int main() {

    std::string s {"hello world"};


    std::string msg = "a" + "b"; // compilation error, no operand is class/enum type

    std::string result = s + "new";

    return 0;
}
