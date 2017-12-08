#include <string>
#include <iostream>

struct Y {

    std::string s;
    int n;
/*
    Y(const std::string& str) : s(str) {
    }

    Y() = default; // allow default initialization with the default meaning
*/

};


int main() {

    Y obj;

    std::cout << obj.s  << ":" << obj.n << std::endl;


    return 0;
}
