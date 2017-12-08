#include <iostream>

template<typename T>
T adder(T v) {
  return v;
}

template<typename T, typename... Args>
T adder(T first, Args... args) {
    std::cout << __PRETTY_FUNCTION__ << "\n";
    return first + adder(args...);
}



int main() {

    long sum = adder(1, 2, 3, 8, 7);

    std::cout << sum << "\n" ;

//    std::string s1 = "x", s2 = "aa", s3 = "bb", s4 = "yy";
//    std::string ssum = adder(s1, s2, s3, s4);
//    std::cout << ssum << std::endl;

    return 0;
}

