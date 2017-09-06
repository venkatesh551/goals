#include <iostream>

template <typename T>
inline T max(T a, T b) {
    return a > b ? a : b;
}

int main()
{
    // This will call max<int> by implicit argument deduction.
    std::cout << max(3, 7) << std::endl;

    // This will call max<double> by implicit argument deduction.
    std::cout << max(3.0, 7.0) << std::endl;

    // This depends on the compiler. Some compilers handle this by defining a template
    // function like double max <double> ( double a, double b);, while in some compilers 
    // we need to explicitly cast it, like std::cout << max<double>(3,7.0);
    std::cout << max(3, 7.0) << std::endl; 

    std::cout << max<double>(3, 7.0) << std::endl;
    return 0;
}
