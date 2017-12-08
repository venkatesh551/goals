#include <iostream>
#include <cmath>

int glob = 0;

constexpr int func1() {
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += i;
    }
    glob = sum;
    return sum;
}


int main() {

   int  a = func1();
    std::cout << a << std::endl;

    return 0;
}
