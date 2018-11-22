#include <iostream>
#include <memory>

class B;

class A {
public:
    void set(std::shared_ptr<B> obj) {
        std::cout << " use count for B obj = " << obj.use_count() << std::endl;
        btypeObj_ = obj;
        std::cout << " use count for B obj = " << obj.use_count() << std::endl;
    }
    ~A() {
        std::cout << "class A dtor called" << std::endl;
    }
private:
    std::shared_ptr<B> btypeObj_;
};

class B {
public:
    void set(std::shared_ptr<A> obj) {
        aTypeObj_ = obj;
    }
    ~B() {
        std::cout << "class B :  dtor called" << std::endl;
    }
private:
    std::shared_ptr<A> aTypeObj_;
};

int main () {

    auto localObjA = std::make_shared<A>();
    auto localObjB = std::make_shared<B>();
    std::cout << "A = " << localObjA.use_count() << std::endl;
    std::cout << "B = " << localObjB.use_count() << std::endl;
    localObjA->set(localObjB);
    std::cout << " use count for B = " << localObjB.use_count() << std::endl;
    localObjB->set(localObjA);
    return 0;
}

