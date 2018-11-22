#include <thread>
#include <iostream>
#include <vector>


struct guardedThread : std::thread {
     using std::thread::thread;
    ~guardedThread() { 
        std::cout << "In dtor : waiting for completeion\n";
        if (joinable()) join(); }
};

void f(int x) {

    std::cout << "In f : "  << x << std::endl;
}

class T {
public:
    void test() {
        std::cout << "test " << std::endl;
    }

};

int main() {

    T obj;
    std::vector<guardedThread> v;
    v.push_back(guardedThread(&T::test, &obj));
    std::cout << "main thread finished" << std::endl;

    return 0;
}
