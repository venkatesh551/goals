#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// function expecting lambda as an argument

void func1(const std::string &s, const std::function<void(std::string , std::string)> &lambda) {

    std::cout << "s = " << s << "\n";
    lambda("hello", "world");

}


int main() {


    func1("hi", [](std::string s, std::string t) {std::cout << s << ":" << t << "\n";});

    std::vector<int> v = {1, 3, 5, 2, 67};
    int count = v.size();
    int m = 2;
//     []{};
    auto z3 =[m]() { if (m) {
                        return 1.0; 
                     } 
                     else {
                         return 2.0; 
                     }
                    };
    auto z4 =[m]() { if (m) {
                        return 1.0; 
                     } 
                     else {
                         return 2.0; 
                     }
                    };
    z3();
    z4();
    // if (z3 == z4) {
        std::cout << "equal" << std::endl;
    // }
    for_each(v.begin(), v.end(), 
            [m, &count](int x)  {
                std::cout << x << " ";
            }
            );

    double (*p1)(double) = [](double a) { return a + 1.0; };
    std::cout << " \n" << p1(2.9) << "\n";
    return 0;
}
