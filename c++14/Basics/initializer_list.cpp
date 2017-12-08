#include <iostream>
#include <initializer_list>

void printList(std::initializer_list<int> values) {

    for (auto val : values) {
        std::cout << val << std::endl;
    }
}

class Test {

    public: Test(int x, int y) : a{x}, b{y} {

            }
    private:
        int a, b, c;
};

int main() {

    printList({1, 2, 3, 4});

    Test obj1(2, 3);
    Test obj2{2, 3};

    return 0;
}

