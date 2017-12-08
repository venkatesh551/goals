#include <new>
#include <iostream>
#include <vector>

class Point {

public:
    Point(int x, int y): a{x}, b{y} {
        
    }

private:
    int a, b;
    char temp[1000000];
};

int main() {
    std::vector<Point *> v;
    while (true) {
        Point* p = new(std::nothrow) Point{2, 3};
        // allocate n ints on the free store
        if (p == nullptr) {// no memory available
            // ... handle allocation error ...
            std::cout << "out of memory" << std::endl;
            return 1;
        }
        v.push_back(p);
    }
    // operator delete(p, std::nothrow); // deallocate *p
    return 0;
}
