#include <iostream>


class Point {

public:
    Point() : x{}, y{}{
    }

    Point(const Point &other) {
        x = other.x;
        y = other.y;
        std::cout << "copy ctor" << std::endl;
    }
    Point (Point && other) {
        x = other.x;
        y = other.y;
        std::cout << "move ctor" << std::endl;
    }

private:
    int x; 
    int y;
};

class A {

public:

    A(int x, Point && c) : a{x}, t{c} {
    }

private:
    int a;
    Point t;
};




int main() {
    A obj{23, Point{}};


    return 0;
}
