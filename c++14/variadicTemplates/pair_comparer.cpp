#include <iostream>

template<typename T>
bool pair_comparer(T a, T b) {
  // In real-world code, we wouldn't compare floating point values like
  // this. It would make sense to specialize this function for floating
  // point types to use approximate comparison.
  return a == b;
}

template<typename T, typename... Args>
bool pair_comparer(T a, T b, Args... args) {
  return a == b && pair_comparer(args...);
}



int main() {

    std::cout << std::boolalpha << pair_comparer(1.5, 1.5, 2, 2, "6", "6");
    // std::cout << std::boolalpha << pair_comparer(1.5, 1, 2, 2, "6", "6");
    // std::cout << std::boolalpha <<  pair_comparer(1.5, 1.5, 2, 2, 6, 6, 7);
    std::cout << "\n";
    return 0;
}
