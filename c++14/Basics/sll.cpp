#include <forward_list>
#include <iostream>

class Base {

public:
    virtual void print() {
        std::cout << "Base : print function" << std::endl;
    }

};

class Derived : public Base {

public:
    void print() override {
        std::cout << "Derived ### function" << std::endl;
    }

};


int main()
{
    std::forward_list<int> sll;
    sll.push_front(20);

    Derived d;
    Base b = d;
    b.print();

    return 0;
}
