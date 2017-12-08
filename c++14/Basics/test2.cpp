#include <iostream>

class Base {

    public:
        int a {3};
};


class D : public Base {

    public:
        void print() {
            std::cout << a << " : " << x << std::endl;
        }
    private:
        int x {2};

};


class A {

    public:
        A operator+(A & src) {
            x += src.x;
            return *this;
        }

        void print() {
            std::cout << x << std::endl;
        }

    private:
        int x {10};

};

class X {
public:
// members (with implicit this pointer):
    X* operator&();
    X operator&(X);
    X operator++(int);
//    X operator&(X,X);
//    X operator/();
};

// nonmember functions :
X operator-(X);
X operator-(X,X);
X operator--(X&,int);
// X operator-();
// X operator−(X,X,X);
// X operator%(X);

int main() {

    A obj;
    obj.print();
    obj.operator+(A{});
    obj.print();

    return 0;
}
