#include <iostream>

std::string fun(std::string str) {

    return str;

}

int main() {

    std::string s{"hh"};

    std::cout << (fun(s) += "a") << std::endl;

    return 0;
}
