#include <iostream>

// The standard library reserves all suffixes not starting with an initial
// underscore, so define your suffixes starting with an underscore

long double operator"" _km(long double x) {

    return x * 1000.0;
}

int main() {

    long double v = 123.9_km;
    std::cout << v << std::endl;
}
