#include <tuple>
#include <iostream>


int main() {

    std::tuple<double, int, char> x{1.1, 42, 'a'};
//    std::cout << x << "\n";
    constexpr int idx = 1;
     std::cout << std::get<idx>(x) << "\n";
    std::cout << std::get<1>(x) << "\n";


    return 0;
}
