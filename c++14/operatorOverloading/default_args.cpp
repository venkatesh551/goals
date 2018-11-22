#include <iostream>


class X {
public:
    X(int);
    void operator+(int);
};
void operator+(X, int);
void operator+(X,double);
void f(X a) {
     a+1;    // same as  a.operator+(1)
//    1+a;    // ::operator+(X(1),a)
//    a+1.0;  // ::operator+(a,1.0)
}
