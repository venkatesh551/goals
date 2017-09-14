#include <iostream>

template <class T>
class Test {
    
    private:
        T data;
    public:
        Test();
        void print();
};

template<typename C>
Test<C>::Test() {

}


template <typename C>
void Test<C>::print() {
    std::cout << "test class object\n";
}

int main()
{
    Test<int> abc;
    abc.print();
    return 0;
}
