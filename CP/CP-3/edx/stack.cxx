#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>

template <class T>
class Stack {
    private:
        std::vector<T> v;
    public:
        void push(T const &ele) {
            v.push_back(ele);
        }
        T pop() {
            if (empty()) {
                throw std::out_of_range("Stack<>::top(): empty stack");
            } else {
                int top_ele = v.back();
                v.pop_back();
                return top_ele;
            }
        }
        bool empty() {
            return v.empty();
        }
    
};

int main ()
{
    std::ifstream ifs("input.txt");
    std::ofstream ofs("output.txt");

    int n;
    
    ifs >> n;
    Stack<int> s;    
    for (int i = 0; i < n; ++i) {
        char ch;
        
        ifs >> ch;
        if (ch == '+') {
            int ele;
            ifs >> ele;
            s.push(ele);    
        } else {
            ofs << s.pop() << std::endl;
        }       
    }
    return 0;
}

