#include <cstdio>
#include <cstdlib>

class Point {

public:
    Point(int x, int y) : a{x}, b{y} {
        printf("ctor called\n");
    }

private:
    int a, b;
};

void * operator new (size_t size) noexcept {

    // void *ptr = malloc(size);
    void *ptr = nullptr;
    std::printf("%p\n", ptr);
    return ptr;

}

int main() {

    Point *p = new Point{2, 3};
    // allocate n ints on the free store
    if (p == nullptr) {// no memory available
        printf("ctor is not invoked\n");
    }
    std::printf("%p\n", p);
    // delete(std::nothrow) p;

    return 0;
}
