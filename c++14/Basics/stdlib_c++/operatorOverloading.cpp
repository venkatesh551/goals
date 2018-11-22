#include <vector>
#include <iostream>

namespace utils {

    class Test {
    public:
        int getSize() const {
            return size;
        }
    private:
        int size{};
    };

}


namespace utils {

bool operator == (const Test &a, const Test &b) {
    return a.getSize() == b.getSize();
}

}

using namespace utils;

int main() {

    std::vector<Test> a(2), b(3);
    std::cout << (a == b) << std::endl;

    return 0;
}

