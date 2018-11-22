#include <iostream>
#include <array>

int main() {

    std::array<int, 4> a1{1, 2, 4};
    for (const auto &ele : a1) {
        std::cout << ele << std::endl;
    }
    std::cout << "a1[5] = " << a1[5] << std::endl;

    return 0;
}
