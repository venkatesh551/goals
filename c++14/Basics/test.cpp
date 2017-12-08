#include <vector>
#include <iostream>
#include <memory>


class Test {

    public:
        int size() {
            return v.size();
        }
    private:
        std::vector<int> v {std::vector<int>(9)};

};

void func(const int &x) {
    std::cout << x << std::endl;
}

void testVector(const std::vector<std::string> &v) {

    for (const auto &ele: v) {
        std::cout << ele << std::endl;
    }
}

constexpr int f1(int x) {
    return 10 + x;
}

void g(int x) {
    std::cout << "x = " << (x + 10) << std::endl;
}

void g(const int x) {
    std::cout << "const x is = " << x << std::endl;
}

int main() {

    g(10);
    std::vector<std::string> a = {"a", "b", "x"};
    testVector(a);
    func(int{2});
    int m = 10;
    std::cout << f1(m) << std::endl;
    Test obj;
    Test obj2{obj};

    std::cout << obj.size() << std::endl;

    return 0;
}
