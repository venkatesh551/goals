#include <memory>
#include <iostream>


class Base {

public:
    virtual ~Base() = default;
private:
    int x;
    float y;
};

class Derived : public Base {

    public:

    ~Derived() {
        std::cout << "size = " << sizeof(Derived) << std::endl;
    }

    private:
        int z;
};


int main() {


    Base *b = new Derived;
    std::unique_ptr<int> p{new int{9}};

    int *q = p.operator->();

    std::cout << *q << std::endl;

    delete b;

    return 0;
}
