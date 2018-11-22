
struct B {
    virtual int operator= (int);
    virtual B& operator= (const B&);
};

struct D : B {
    virtual int operator= (int);
    virtual D& operator= (const B&);
};

D dobj1;
D dobj2;
B* bptr = &dobj1;

void f() {
    bptr->operator=(99);    // calls D::operator=(int)
    *bptr = 99;             // ditto
    bptr->operator=(dobj2); // calls D::operator=(const B&)
    *bptr = dobj2;          // ditto
    dobj1 = dobj2;          // calls implicitly-declared D::operator=(const D&)
}

int main() {
    return 0;
}
